#include <stdio.h>

int main(){
    int num[5];
    int i=0;
    int max = 0;


    //Repeat 5 times
    for(i=0;i<5;i++){
        //Read an integer x
        printf("Input an integer: ");
        scanf("%d",&num[i]);
         //If 𝑥 is greater than 𝑚𝑎𝑥, update max with x
        if(num[i]>max) max = num[i];
   }

    //Print max
    printf("maximum = %d\n",max);

    return 0;
}