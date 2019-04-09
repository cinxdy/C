#include <stdio.h>
#include <ctype.h>

void RotateString_Left(char str[]);

int main(){

    char text[256]; 

    printf("Input a text line: "); 
    gets(text);
    printf("text = [%s]\n", text);

    for(int i = 0; i < strlen(text); i++){
        RotateString_Left(text);
        printf("text = [%s]\n", text);
    }

    return 0;

}

void RotateString_Left(char str[]){

    int len=0;
    char temp=0;

    len=strlen(str);

    temp=str[0];
    for(int i=0;i<len-1;i++){
        str[i]=str[i+1];
    }
    str[len-1]=temp;

}