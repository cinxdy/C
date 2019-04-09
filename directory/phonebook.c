#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 64

//gcc phonebook.c Console.c -D_MAC

typedef struct entry{
    char name[MAX_LEN];
    char phone[MAX_LEN];
} ContactEntry;

void ReadPhonebook(ContactEntry array[],int* size);
void SavePhonebook();
void FindName(ContactEntry array[], int size);
void DisplayPhonebook (ContactEntry array[],int size);

int main(){
    int i = 0;
    int N = 0;
    int x = 0;
    char book[MAX_LEN]={0};

    ContactEntry *phonebook = NULL;
    phonebook = (ContactEntry *)malloc(N * sizeof(ContactEntry *));
    //if faile to allocate memory
    if(phonebook == NULL) {
        printf("Failed to allocate memory!\n");
        exit(-1);
    }

    while(1){
        printf("Type the number of what to do\n 1) Save the number\n 2) Find the number\n 3) Display all numbers\n 4) quit\n");
        scanf("%d",&x);

        switch(x){
            case 1: SavePhonebook(); 
                    break;
            case 2: ReadPhonebook(phonebook,&N);
                    FindName(phonebook,N); 
                    break;
            case 3: ReadPhonebook(phonebook,&N);
                    DisplayPhonebook(phonebook,N); 
                    break;
            case 4: return 0;
            default: printf("Input 1,2,3,4\n");
                    break;
        }
    }

    //Release dynamically allocated memory
    free(phonebook);
    
}


void ReadPhonebook(ContactEntry array[],int* size){

    FILE *fp = NULL;
    char book[MAX_LEN]={0};

    while(1){
        printf("Type the name of phone book which you want to read\n");
        scanf("%s",book);

        fp = fopen(book,"rt");
        //if fail to open file
        if(fp == NULL)
            printf("Failed to open file!\n");

        else break;
    }

    //how many phone numbers
    fscanf(fp,"%d",size);

    for(int i=0;i<*size;i++)
        fscanf(fp,"%s %s",array[i].name,array[i].phone);

    printf("Success to Read the phonebook <%s>!\n\n",book);
    
    fclose(fp);
}

void SavePhonebook(){
    char book[MAX_LEN]={0};
    int i=0, size=0;
    FILE *fp = NULL;

    printf("Type the name of phone book which you want to save\n");
    scanf("%s",book);

    fp = fopen(book,"wt");
    printf("How many people would you want to save?\n");
    scanf("%d",&size);

    fprintf(fp,"%d\n",size);

    char tempname[MAX_LEN]={0};
    char tempnumber[MAX_LEN]={0};
    while(i<size){
        printf("%d-th : Type the name and numbers (name 010-0000-0000)\n",i+1);
        scanf("%s %s",tempname,tempnumber);

        if(tempnumber[3]!='-' || tempnumber[8]!='-'){
            printf("failed to save! Check the number you entered\n");
        }
        else {
        fprintf(fp,"%s %s\n",tempname,tempnumber);
        i++;
        }
    }
    
    printf("Success to Save the phonebook <%s>!\n\n",book);
    fclose(fp);
}

void FindName(ContactEntry array[], int size){
    int i=0;
    char targetName[MAX_LEN]={0};
    int index = 0;

    //Read target names and print the numbers.
    //Repeat
    while(1){
        //Read target name from the user
        printf("Type name to find: (if you want to quit, type quit)\n");
        scanf("%s",targetName);

        //Repeat with respect to i from 0 to size
        index=-1;
        for(i=0;i<size;i++){
            //If array[i].name matches targetName, return i;
            if(!strcmp(array[i].name,targetName))
                index = i;
        }

        //If name is “quit” break the loop
        if(!strcmp(targetName,"quit")) break;

        //If the index is -1, print “No entry <name>!”
        //Otherwise, print the name and phone number
        if(index==-1) printf("No entry <%s>!\n",targetName);
        else printf("name = %s , phone number = %s\n",array[index].name,array[index].phone);
    }

}

void DisplayPhonebook (ContactEntry array[],int size){
    int i=0;
    for(i=0;i<size;i++){
        printf("%d\t %15s\t %12s\n",i+1,array[i].name,array[i].phone);
    }
    printf("Success to Display Phonebook!\n\n");
}
