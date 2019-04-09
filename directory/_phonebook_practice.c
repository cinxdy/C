#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 64

typedef struct {
	char name[MAX_LEN];
	char phone[MAX_LEN];
} ContactEntry;

void DisplayPhonebook(ContactEntry phonebook[], int size);
int SearchByName(ContactEntry phonebook[], int size, char name[]);


int main()
{
	ContactEntry *phonebook = NULL;
	int N = 0;
	FILE *fp = NULL;
	int i = 0;

	// read phonebook from file
	fp = fopen("phone.txt", "r");
	if(fp == NULL){
		printf("Failed to open file phone.txt\n");
		exit(-1);
	}

	// read # of entries
	fscanf(fp, "%d", &N);
	
	// allocate phonebook array
	phonebook = (ContactEntry*)malloc(N * sizeof(ContactEntry));
	if(phonebook == NULL){
		printf("Failed to allocate memory.\n");
		exit(-1);
	}

	// read phonebook entries from the file
	for(i = 0; i < N; i++){
		fscanf(fp, "%s %s", phonebook[i].name, phonebook[i].phone);
	}

	// close the file
	fclose(fp);


	// display phonebook
	DisplayPhonebook(phonebook, N);


	// repeat
	while(1){
	//      read a name
		char name[MAX_LEN];
		printf("Input name: ");
		scanf("%s", name);

		if(strcmp(name, "quit") == 0)
			break;

	//      search the name
		i = SearchByName(phonebook, N, name);

	//      display phone number
		if(i >= 0)
			printf("name = %s, phone number = %s\n", phonebook[i].name, phonebook[i].phone);
		else
			printf("No entry name %s\n", name);
	}

	free(phonebook);

	return 0;
}
void DisplayPhonebook(ContactEntry phonebook[], int size)
{
	int i = 0;

	for(i = 0; i < size; i++){
		printf("%3d %16s\t%16s\n", i, phonebook[i].name, phonebook[i].phone);
	}
}

int SearchByName(ContactEntry phonebook[], int size, char name[])
{
	int i = 0;

	for(i = 0; i < size; i++){
		if(strcmp(phonebook[i].name, name) == 0)
			return i;
	}

	return -1;
}