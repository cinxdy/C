#include <stdio.h>
#include <ctype.h>

int main(){
    char text[1000];
    int upper=0, lower=0, digit=0, space=0;
    int enter=0;

    printf("Input a text. Type a blank line to finish.\n\n");
    //Repeat following actions
    enter=0;
    while(1){
        //Read a text line from the user
        gets(text);
        
        //If the input is an empty string, break the loop
        if(text[0]==0){
            space--;//delete end of enter
            break;
        }

        //Count each char types in the text line
        for(int i=0;text[i]!=0;i++){
            if(isupper(text[i])){
                upper++;
            }
            if(islower(text[i])){
                lower++;
            }
            if(isdigit(text[i])){
                digit++;
            }
            if(isspace(text[i])){
                space++;
            }
        }
        enter++;
        
    }
    //add enter
    space+=enter;
        
    //Print the results
    printf("The text has %d uppercase chars, %d lowercase chars, %d digits, and %d whitespace characters.\n",upper,lower,digit,space);

    return 0;

}