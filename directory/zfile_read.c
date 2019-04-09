#include <stdio.h>

int main()
{
    FILE *fp = NULL;
    fp = fopen("number.txt", "rt");

    for(int i = 0; i < 100; i++){
        int x = 0;
        fscanf(fp, "%d", &x);
        printf("%dth number is %d \n", i+1, x);
    }

    printf("\n");
    fclose(fp);

    return 0;
}