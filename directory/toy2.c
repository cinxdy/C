#include <stdio.h>
#include "Console.h"

int main(){
    int screenwidth = getWindowWidth();
    int screenheight = getWindowHeight();
    int x=0, y=screenheight/2;
    
    printf("Press Enter to start:");
    getchar();
    clrscr();

    while(1){

        //erase current coordinate
        gotoxy(x,y);
        putchar(' ');
        
        //move coordinate
        x+=10;
        putchar('>');
        if(x > screenwidth) x=1;

        //draw new coordinate
        gotoxy(x,y);
        putchar(' ');

        MySleep(1000);

    }
}