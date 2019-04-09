#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILE_NAME "number.txt"

int main()
{
    srand(time(NULL));
    FILE *fp = NULL;
    // open a file
    fp = fopen(FILE_NAME, "wt");

    // print numbers into the stream (fp)
    for(int i = 0; i < 100; i++)
        fprintf(fp, "%d ", rand()%100+1 );

    // close file
    fclose(fp);

    return 0;
}