#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void CountingText(char text,int* upper,int* lower,int* digit,int* space);

int main(){

    FILE *in=NULL;
    char text=0;
    char filename[100];
    int upper=0,lower=0,digit=0,space=0;

    //Read the name of a text file
    printf("Input filename: ");
    scanf("%s",filename);
    in = fopen(filename,"r");

    while((text=getc(in))!=EOF){
        CountingText(text,&upper,&lower,&digit,&space);
    }

    printf("The text has %d uppercase chars, %d lowercase chars, %d digits, and %d whitespace characters.\n",upper,lower,digit,space);

}

void CountingText(char text,int* upper,int* lower,int* digit,int* space){

    //Count each char types in the text line
    if(isupper(text)){
        (*upper)++;
    }
    if(islower(text)){
        (*lower)++;
    }
    if(isdigit(text)){
        (*digit)++;
    }
    if(isspace(text)){
        (*space)++;
    }
}
