#include <stdio.h>

int main(){

    int lower = 0, upper = 0;
    int guess=0;
    char answer = 0;

    //tell the user to select a number between 1 to 100
    printf("select a number between 1 to 100\n");
    //initialize lower by 1 and upper by 100
    lower = 1; upper = 100;

    //repeat until upper <= lower
    while(lower<=upper){
        guess = (upper+lower)/2;
        //hit average of upper and lower
        printf("How about %d?",guess);
        //read user's response
        scanf(" %c",&answer);

        //if guess is too large
        if(answer == '>') lower = guess +1;
        //if guess is too small
        else if(answer == '<') upper = guess -1;
        //if = print message
        else if(answer == '=') {
            printf("thank you for playing\n");
            break;
        }

    }
}