#include <stdio.h>

int main(){

    char first_name[32],middle_name[32],last_name[32];
    char gender=0;

    //input full name
    printf("Input your full name (first middle last):");
    scanf("%s %s %s",first_name,middle_name,last_name);

    //Input gender
    printf("Input your gender (m or f):");
    scanf(" %c",&gender);

    //You name is Injung E. Kim
    printf("You name is %s %c. %s\n",first_name,middle_name[0],last_name);

    //Nice to see you Mr. Kim.
    printf("Nice to see you "); //nice to meet you
    //gender
    if(gender=='m') printf("Mr."); //male
    else printf("Ms."); //female
    printf("%s.\n",last_name); //last name

    return 0;
}