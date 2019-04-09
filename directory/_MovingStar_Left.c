/*

	Compilation:
		gcc MovingStar_Left.c Console.c -D_WINDOWS		// on Windows
		gcc MovingStar_Left.c Console.c -D_MAC			// on Mac

*/


#include <stdio.h>

#include "Console.h"

int main()
{
    int screenWidth = getWindowWidth();
    int screenHeight = getWindowHeight();
    int x = 1, y = screenHeight / 2;

	clrscr();

	while(1){
        // erase previous coordinate
        gotoxy(x, y);
        putchar(' ');

        // update coordination (x++)
        x++;
        if(x > screenWidth)
            x = 1;

        // draw at the new coordinate
        gotoxy(x, y);
        putchar('*');

        fflush(stdout);         // necessary on MAC

        // put delay
        MySleep(100);
    }

    return 0;
}