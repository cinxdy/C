#include <stdio.h>
#include <ctype.h>

int main(){
    char text[1000];
    int upper=0, lower=0, digit=0, space=0;

    printf("Input a text. Type a blank line to finish.\n\n");
    //Repeat following actions
    while(1){
        //Read a text line from the user
        gets(text);

        //If the input is an empty string, break the loop
        if(text[0]==0){
            break;
        }

        //Count each char types in the text line
        for(int i=0;text[i]!=0;i++){
            if(text[i]>=0x41 && text[i]<=0x5A){
                upper++;
            }
            if(text[i]>=0x61 && text[i]<=0x7A){
                lower++;
            }
            if(text[i]>=0x30 && text[i]<=0x39){
                digit++;
            }
            if(isspace(text[i])){
                space++;
            }
        }
    }
        
    //Print the results
    printf("The text has %d uppercase chars, %d lowercase chars, %d digits, and %d whitespace characters.\n",upper,lower,digit,space);

    return 0;

}