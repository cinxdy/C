#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    
    int x =0;
    int num[10]={0};
    int mostx=0;
    int sum=0;

    for(int i=0;i<1000;i++){
        x= rand()%10;
        num[x]++;
    }
    
    for(int i=0;i<10;i++){
        printf("%d: %d times\n",i,num[i]);

        sum+=num[i];
    }

    mostx=0;
    for(int i=0;i<10;i++){
        if(num[mostx]<num[i])
            mostx=i;
    }

    printf("Sum of frequencies of all digits: %d\n",sum);
    printf("The most frequent digit is %d (%d times)\n",mostx,num[mostx]);
    
}