#include <stdio.h>


int GetDigit(int x,int place);

int main(){
    int number=0;

    //Read a large int
    printf("Input a large integer (maximum 8 digits): ");
    scanf("%d",&number);

    for(int i=0;i<8;i++){
        if(GetDigit(number,i)!=0){
            printf("%d-th digit: %d\n",i+1,GetDigit(number,i));
        }
    }

    return 0;

}

int GetDigit(int x,int place){
    int power=1;
    int result=0;
    
    for(int i=0;i<place;i++){
        power*=10;
    }

    result= (x / power) % 10;

    return result;
}