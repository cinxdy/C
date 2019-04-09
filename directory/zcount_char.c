#include<stdio.h>
#define MAX_LEN 256


int CountCharacter(char str[]);
int CountWord(char str[]);

int main(){
    
    char text[MAX_LEN];

    //read a text line from the user
    printf("Input a text line.\n");
    gets(text);

    //print the result
    printf("String \"%s\"has %d characters and %d words.\n",text,CountCharacter(text),CountWord(text));

    return 0;

}

int CountCharacter(char str[]){
    int no_char =0;

    while(str[no_char]!=0){
        no_char++;
    }

    return no_char;
}

int CountWord(char str[]){
    int i=0;
    int no_word=0;

    while(str[i]!=0){
        if(str[i]!=' ' && (i==0 || str[i-1]==' ')){
            no_word++;
        }

        i++;
    }
    return no_word;
}