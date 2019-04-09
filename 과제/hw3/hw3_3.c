#include<stdio.h>

int main(){
    int i = 0, j = 0; 
    int height = 0;

    //높이 입력받기
    printf("Input the height of triangle: "); 
    scanf("%d", &height);

    for(i = 0; i < height; i++){ //높이는 height번
        for(j = 0; j < height-i; j++){ //*이 height - i 개 
         printf("*");
        }
    printf("\n");
    }

return 0;
    
}