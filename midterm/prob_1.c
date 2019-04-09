#include <stdio.h>

int main(){

    char name[2][25];
    int year[2]={0};
    int young=0;

    //Read the names and birth years
    for(int i=0;i<2;i++){
        printf("Player #%d, please input your name: ",i+1);
        scanf("%s",name[i]);
        printf("Input your birth year: ");
        scanf("%d",&year[i]);
    }

    //Decide who is younger than the other.
    if(year[0]<year[1]) young=1;
    else if (year[0]>year[1]) young=0;
    else if(year[0]==year[1]) young=-1;
        
    //Print result
    if(young!=-1){
        printf("%s is younger than %s.\n",name[young],name[1-young]);
    }
    else {
        printf("%s and %s are the same age.\n",name[0],name[1]);
    }

    return 0;
    
}