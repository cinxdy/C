#include <stdio.h>
#include <string.h>

#include "Console.h"

void FillString(char str[], int len, char v);

int main()
{
    int x = 0, y = 0;
    int dx = 2, dy = 1;
    char message[128];
    int len = 0;
    char empty_string[128];

    int width = getWindowWidth();
    int height = getWindowHeight() - 2;

    x = width / 2;
    y = height / 2;

    clrscr();
    gotoxy(1, 1);
    printf("screen size = %d x %d\n", width, height);
    printf("input a message: ");
    gets(message);
    
    len = strlen(message);
    FillString(empty_string, len, ' ');

    while(1){
        gotoxy(x, y);
        printf("%s", empty_string);

        x += dx;
        if(x < 1 || x + len - 1 > width){
            dx = -dx;
            x += 2 * dx;
        }

        y += dy;
        if(y < 1 || y > height){
            dy = -dy;
            y += 2 * dy;
        }

        gotoxy(x, y);
        printf("%s", message);

        MySleep(50);
    }

    return 0;
}

void FillString(char str[], int len, char v)
{
    int i = 0;

    for(i = 0; i < len; i++)
        str[i] = v;

    str[len] = 0;
}
