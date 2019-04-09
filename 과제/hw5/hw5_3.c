#include <stdio.h>
#include <ctype.h>

void RotateString_Left(char str[]);

int main(){

    char text[256]; 
    int len = 0;
    int i = 0;

    printf("Input a text line: "); 
    gets(text);
    
    len=strlen(text);
    printf("The length of string \"%s\" is %d.\n", text, len);

    printf("text = [%s]\n", text);
    for(i = 0; i < len; i++){
        RotateString_Left(text);
        printf("text = [%s]\n", text); 
    }
return 0;

}

void RotateString_Left(char str[]){

    int i=0;
    int len=0;
    char temp=0;

    len=strlen(str);

    temp=str[0];
    for(i=0;i<len-1;i++){
        str[i]=str[i+1];
    }
    str[len-1]=temp;
    
}