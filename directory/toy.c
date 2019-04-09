#include <stdio.h>
#include "Console.h"

int main(){
    
    int Width = getWindowWidth();
    int Height = getWindowHeight();
    int x=0, y=0;
    int cont = 1, cont2 = 1;

    y = Height / 2 ;

    while(cont){

        clrscr();
        
        if(cont2 == 1){ // Right
            gotoxy(x+=10,y);
            putchar('>');
        }

        if(cont2 == 0){ //Left
            gotoxy(x-=10,y);
            putchar('<');
        }

        if(x > Width) cont2 = 0;
        else cont2 = 1;

        if(kbhit()&&_getch()=='t') cont = 0;

        MySleep(1000);
        
    }
    
}