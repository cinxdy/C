#include <stdio.h>
#include <string.h>

// if necessary, use the following functions declared in string.h
// strlen(str)
// strcmp(str1, str2)
// strcpy(dest, src)
// strcat(dest, src)


char lexicon[1024][64];
int no_word = 0;

void DisplayStringArray(char str_array[][64], int size);
void SortStringArray(char str_array[][64], int size);

int main()
{
    char word[64];
	int ret=0;

	while(1){
		// read strings and put them into lexicon until the user types EOF
		printf("Input words (type EOF to finish.)\n");
		ret = scanf("%s",word);
		if(ret == EOF) break;
		strcpy(lexicon[no_word++],word);

		// print all word in the lexicon
		printf("Before Sorting : \n");
		DisplayStringArray(lexicon,no_word);

		// sort lexicon
		SortStringArray(lexicon,no_word);

		// print all word in the lexicon
		printf("After Sorting : \n");
		DisplayStringArray(lexicon,no_word);
	}

    return 0;
}

void DisplayStringArray(char str_array[][64], int size){

	for(int i=0;i<size;i++){
		printf("str_array[%d]=%s\n",i+1,str_array[i]);
	}

}

void SortStringArray(char str_array[][64], int size){
    
    // the following code is the Selection Sort in the lecture slide
    // Convert it to sort an array of string.

    int current = 0;			// start of the unsorted list

	for(current = 0; current < size - 1; current++){
		int smallest = 0;		// location of the smallest element 
		int walk = 0;		// variable to traverse the unsorted list
		char tempData[64] = {0};		// temporary variable for exchange

		// find the smallest in the unsorted str_array
		smallest = current;
		for(walk = current + 1; walk < size; walk++)
			if(strcmp(str_array[walk], str_array[smallest])<0)
				smallest = walk;

		// exchange the smallest with the first of unsorted str_array
		strcpy(tempData ,str_array[current]);
		strcpy(str_array[current] ,str_array[smallest]);
		strcpy(str_array[smallest] , tempData);
	}
    
}
