#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

//#define SIZE 100

void DisplayArray(int array[], int n);

int main()
{
//    int data[SIZE];
    int *data = NULL;
    int n = 0;

    srand(time(NULL));

    printf("How many random number do you need? ");
    scanf("%d", &n);

    // dynamically allocate array
    data = (int*)malloc(n * sizeof(int));
    if(data == NULL){
        printf("Error! Failed to allocate memory, LINE = %d\n", __LINE__);
//        exit(-1);
    }

    for(int i = 0; i < n; i++)
        data[i] = rand() % 100 + 1;

    DisplayArray(data, n);

    // deallocate array
    free(data);

    return 0;
}

void DisplayArray(int array[], int n)
{
    int i = 0;

    for(i = 0; i < n; i++){
        printf("%3d ", array[i]);
        if((i+1)%10 == 0)
            putchar('\n');
    }
}