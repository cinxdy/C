#include<stdio.h>

int main(){
    unsigned int x = 0;
    int bits[33]={0};
    
    printf("Input an integer to change to binary number.\n");
    scanf("%d",&x);

    unsigned int m = 1 << 31;
    printf("m = %u\n",m);
    
    for(int i = 0 ; i<32 ; i++){
        if(x&m)
            bits[i]=1;
        else bits[i]=0;
        m >>= 1;

        printf("%d",bits[i]);
    }
    printf("\n");

}