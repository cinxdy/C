#include<stdio.h>

int main(){

    double a=0.0, b=0.0;
    char op = 0;
    double result = 0;

    //read a binary expression

    printf("Input a binary expression: ");
    scanf("%lf %c %lf",&a,&op,&b);

    //calculate
    switch(op){
        case '+' : result = a+b; break;
        case '-' : result = a-b; break;
        case '*' : result = a*b; break;
        case '/' : if(b!=0) result = a/b;
                   else {
                      printf("Error! division by zero!\n");
                      result =0;
                  }
                    break;
        default : printf("Input +-*/\n");
    }

    /*
    //calculate
    if(op == '+') result = a+b;
    else if(op == '-') result = a-b;
    else if(op == '*') result = a*b;
    else if(op == '/') {
        if(b==0){
            printf("Error! division by zero!\n");
            result = 0;
        }
        else result = a/b;
    }
    else printf("Input +-* /");
    */

    //displace the result
    printf("%lf %c %lf = %lf\n", a,op,b,result);

    return 0;

}