#include <stdio.h>

void swap(int *a, int *b);

int main(){
    int a =10, b= 20;

    swap(&a,&b);

    printf("After: a = %d, b = %d\n",a,b);
    return 0;

}

void swap ( int* a, int* b ){
    int temp=0;
    printf("in swap, Before: a = %d, b = %d\n",*a,*b);

    //exchange a and b
    temp = *a;
    *a=*b;
    *b=temp;

    printf("in swap, After: a = %d, b = %d\n",*a,*b);
}