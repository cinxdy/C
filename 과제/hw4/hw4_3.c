#include<stdio.h>

void CopyString(char dest[],char src[]);

int main(){
    char text[256] = {0};
    char text2[256] = {0};
    printf("Input a text line: ");
    gets(text);
    printf("text = [%s]\n", text);
    printf("text2 = [%s]\n", text2);
    printf("Calling CopyString(text2, text);\n");
    CopyString(text2, text);
    printf("text = [%s]\n", text);
    printf("text2 = [%s]\n", text2);
    printf("%c\n",text2[5]);
}

void CopyString(char dest[],char src[]){
    int i=0;
    while(1){
        dest[i]=src[i];
        if(src[i]!=0){
            i++;
        }
        else { 
            break;
        }
    }
}
