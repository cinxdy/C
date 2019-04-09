#include <stdio.h>

#define BITS_IN_INT 32

int main()
{
    unsigned int x = 0;
    char bit[33];

    // read an integer
    printf("Input an integer: ");
    scanf("%d", &x);    

    // convert integer into bit string
    unsigned int m = 1 << 31;     // 1000 0000 0000 0000 0000 0000 0000 0000
    int i = 0;
    for(i = 0; i < 32; i++){
        if(x & m)
            bit[i] = '1';
        else
            bit[i] = '0';
        m >>= 1;
    }
    bit[32] = 0;

    // print bit string
    printf("%d (0x%x) = %s\n", x, x, bit);

    return 0;
}