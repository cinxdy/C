#include <stdio.h>

int main(){

    printf("-----------------------\n");
    printf("int size : %ld byte\n",sizeof(int));
    printf("float size : %ld byte\n",sizeof(float));
    printf("long size : %ld byte\n",sizeof(long));
    printf("double size : %ld byte\n",sizeof(double));
    printf("char size : %ld byte\n",sizeof(char));
    
    return 0;
}