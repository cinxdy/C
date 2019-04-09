#include <stdio.h>

void ReplaceCharacter(char text[],char c1, char c2);

int main(){
    char text[1000]={0};
    char c1=0, c2=0;

    printf("Input a text line: ");
    gets(text);

    printf("Input two characters c1 and c2: ");
    scanf("%c %c",&c1,&c2);
    
    printf("Before: \"%s\"\n",text);
    ReplaceCharacter(text,c1,c2);
    printf("After: \"%s\"\n",text);

    return 0;
}


void ReplaceCharacter(char text[],char c1, char c2){

    for(int i=0;text[i]!=0;i++){
        if(text[i]==c1){
            text[i]=c2;
        }
    }

}