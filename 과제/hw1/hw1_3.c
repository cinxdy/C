#include <stdio.h>


int main(){

int a=0,b=0,c=0,d=0;

printf("Input a 3-digit integer: ");
scanf("%d", &a);

b = (a/100) % 10;
c = (a/10) % 10;
d = a % 10;

printf("%d is composed of [%d,%d,%d]\n",a,b,c,d);

return 0;

}