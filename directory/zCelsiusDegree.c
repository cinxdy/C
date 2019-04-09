#include <stdio.h>

int main(){
    float celsius = 0.0;
    float fahr=0.0;

    printf("fahr? :");
    scanf("%f",&fahr);

    celsius = (fahr-32)*5/9;

    printf("celsius degree is %fC",celsius);
    return 0;

}