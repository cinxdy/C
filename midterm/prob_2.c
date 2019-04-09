#include <stdio.h>

int main(){
    int min_even=1001;
    int max_odd=0;
    int min=0;
    int max=0;
    int n=0;
    int testEOF=0;

    //Read numbers between 0 and 1000 until EOF
    while(1){
        //input a number N
        printf("Input a number between 0 and 1000: ");
        
        //break if the user inputs EOF
        testEOF=scanf("%d",&n);
        if(testEOF==EOF) {
            printf("\n");
            if(min>0){
                printf("Minimum even number is %d.\n",min_even);
            }
            else printf("No even number.\n");

            if(max>0){
                printf("Maximum odd number is %d.\n",max_odd);
            }
            else printf("No odd number.\n");

            break;
        }
        
        if(n>=0 && n<=1000){
            if(n%2==0 && n<min_even){
                min_even = n;
                min++;
            }
            if(n%2==1 && n>max_odd){
                max_odd = n;
                max++;
            }
        }
    }

    return 0;
}