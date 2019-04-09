#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *in = NULL, *out = NULL;
    int c = 0;

    // open source and destination files
    in = fopen("src_file.txt", "r");
    out = fopen("dest_file.txt", "w");
    if(in == NULL || out == NULL){      // check file open error
        printf("Failed to open file.\n");
        exit(-1);
    }

    // copy all characters from src to dest
    while((c = fgetc(in)) != EOF)
        fputc(c, out);

    // close files
    fclose(in);
    fclose(out);

    return 0;
}