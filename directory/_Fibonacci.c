#include <stdio.h>
#include <stdarg.h>

int tab_printf(int level, char *format, ...);
int Fibonacci(int n, int level);

int main()
{
    int n = 0;
    int fib = 0;

    printf("Input an integer: ");
    scanf("%d", &n);

    fib = Fibonacci(n, 0);
    printf("Fibonacci(%d) = %d\n", n, fib);

    return 0;
}

int Fibonacci(int n, int level)
{
    tab_printf(level, "Fibonacchi(%d, %d)\n", n, level);

    if(n == 0 || n == 1){
        tab_printf(level, "Return %d\n", n);
        return n;
    } else {
        tab_printf(level, "Calling Fibonacchi(%d, %d)\n", n - 1, level + 1);
        int prev1 = Fibonacci(n-1, level + 1);

        tab_printf(level, "Calling Fibonacchi(%d, %d)\n", n - 2, level + 1);
        int prev2 = Fibonacci(n-2, level + 1);

        tab_printf(level, "Return %d + %d\n", prev1, prev2);
        return prev1 + prev2;
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

