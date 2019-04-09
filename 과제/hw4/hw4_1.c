#include<stdio.h>

int Accumulate(int n);


int main(){
    int n=0;
    int testEOF=0;

    //repeat
    while(1){
        //input a number N
        printf("Input a number N: ");
        
        //break if the user inputs EOF
        testEOF=scanf("%d",&n);
        if(testEOF==EOF) {
            printf("Bye!\n");
            break;
        }
        
        //output sum
        printf("Sum of numbers from 1 to N is %d\n",Accumulate(n));
    }
    
    return 0;
}


int Accumulate(int n){
    int sum = 0;
    int i = 1;
    while(i<=n){
        sum +=i;
        i++;
    }
    return sum;
}