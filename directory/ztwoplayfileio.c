#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILE_NAME "number.txt"

int main(){
    srand(time(NULL));
    FILE *fpw = NULL, *fpr=NULL;
    int a=0;

    // open a file
    fpw = fopen(FILE_NAME,"wt");

    for(int i = 0; i<100 ; i++){
        fprintf(fpw,"%d ",rand()%100+1);
    }
    fclose(fpw);

    fpr = fopen(FILE_NAME,"rt");

    for(int i = 0; i<100 ; i++){
        fscanf(fpr,"%d ",&a);
        printf("%d ",a);
    }

    fclose(fpr);

}