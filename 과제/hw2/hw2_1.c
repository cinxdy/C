#include <stdio.h>

int main(){

    char a=0, b=0, c=0;
    //input three characters
    printf("input three characters:");
    scanf("%c %c %c",&a,&b,&c);

    //ascending order and print
   if(a<b) {
       if(b<c) printf("%c-%c-%c",a,b,c); //abc
       else {
            if(a<c) printf("%c-%c-%c",a,c,b); //acb
            else printf("%c-%c-%c",c,a,b); //cab
       }
   }

   else {
        if(a<c) printf("%c-%c-%c",b,a,c); //bac
        else {
            if(b<c) printf("%c-%c-%c",b,c,a); //bca
            else printf("%c-%c-%c",c,b,a); //cba
        }
   }

    printf("\n");
    return 0;

}