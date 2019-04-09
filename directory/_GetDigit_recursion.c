#include <stdio.h>
#include <stdarg.h>

int tab_printf(int level, char *format, ...);
int GetDigit(int x, int place, int level);

int main()
{
    int x = 0;
    int place = 0;
    int digit = 0;

    printf("Input a large integer (maximum 8 digits) and place: ");
    scanf("%d", &x);
    printf("Input place of the digit to extract: ");
    scanf("%d", &place);

    digit = GetDigit(x, place, 0);
    printf("%d-th digit of %d is %d\n", place, x, digit);

    return 0;
}

int GetDigit(int x, int place, int level)
{
    tab_printf(level, "GetDigit(%d, %d, %d)\n", x, place, level);

	if(place == 1){
        tab_printf(level, "Return %d\n", x % 10);
		return x % 10;
	} else {
        tab_printf(level, "Recursion. Calling %s(%d, %d, %d)\n", __FUNCTION__, x / 10, place - 1, level + 1);
		return GetDigit(x / 10, place - 1, level + 1);
    }
}

int tab_printf(int level, char *format, ...)
// print message at the specified level
// usage : same with printf(const char *format, …) except for the first parameters that specifies the level
{
	va_list vl;					// in varargs.h
    int i = 0;
    int ret = 0;

    for(i = 0; i < level; i++)
        printf("  ");

	va_start(vl, format);
	ret = vprintf(format, vl);
	va_end(vl);

    return ret;
}

