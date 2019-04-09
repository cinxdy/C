#include <stdio.h>

#include "Console.h"

enum LogicValue { FALSE, TRUE };

typedef struct tFighter {
    int x, y, width;
    int dx, dy;
    int delay;
} Fighter;

void DrawFighter(Fighter *fighter);
void EraseFighter(Fighter *fighter);
void MoveFighter(Fighter *fighter, int screenWidth, int screenHeight);

// Problem 2
// TO DO: Define a structure "Missile"
// 	The fields of Missile { x, y, delay, and active }

/* uncomment this code after defining tht Missile structure
void MoveMissile(Missile *missile, int screenWidth, int screenHeight);
*/


int main()
{
    int screenWidth = getWindowWidth();
    int screenHeight = getWindowHeight() - 1;
    int cont = TRUE;

    int t = 0;

    Fighter fighter = { screenWidth / 2, screenHeight / 2, 5, 0, 0, 5 };

/* uncomment this code after defining tht Missile structure
    Missile missile;
    missile.active = FALSE;
*/

    clrscr();
    printf("Move the fighter by 'j' 'l', 'i', 'k' keys and shoot missile by space key.\n");
    printf("Press enter to start: ");
    getchar();

    while(cont){
        gotoxy(screenWidth, 1);
        if(kbhit()){
            char key = _getch();

            switch(key){
            case 'q':
                cont = 0;
                break;

            case 'j':
                fighter.dx = -1;
                fighter.dy = 0;
                break;

            case 'l':
                fighter.dx = 1;
                fighter.dy = 0;
                break;

            case 'i':
                fighter.dx = 0;
                fighter.dy = -1;
                break;

            case 'k':
                fighter.dx = 0;
                fighter.dy = 1;
                break;

            case ',':
                fighter.dx = 0;
                fighter.dy = 0;
                break;

            case ' ':
/* uncomment this code after defining tht Missile structure
                if(missile.active == FALSE){
                    missile.x = fighter.x;
                    missile.y = fighter.y - 1;
                    missile.delay = 3;
                    missile.active = TRUE;
                }
*/
                break;
            }
        }

        if(t % fighter.delay == 0)
            MoveFighter(&fighter, screenWidth, screenHeight);

/* uncomment this code after defining tht Missile structure
        if((missile.active == TRUE) && (t % missile.delay == 0))
            MoveMissile(&missile, screenWidth, screenHeight);
*/
        MySleep(10);
        t++;
    }

    return 0;
}

void DrawFighter(Fighter *fighter)
{
    int i = 0;
    gotoxy(fighter->x - fighter->width / 2, fighter->y);
    putchar('<');
    for(i = 1; i < fighter->width-1; i++){
        if(i == fighter->width / 2)
            putchar('A');
        else
            putchar('=');
    }
    putchar('>');
}

void EraseFighter(Fighter *fighter)
{
    int i = 0;
    gotoxy(fighter->x - fighter->width / 2, fighter->y);
    for(i = 0; i < fighter->width; i++)
        putchar(' ');
}

void MoveFighter(Fighter *fighter, int screenWidth, int screenHeight)
{
	// Problem 1: complete this function

	// erase the fighter at the current coordinate
	EraseFighter(fighter);

	// update x coordinate.
    fighter->x += fighter->dx;
    if(fighter->x < fighter->width / 2 + 1){
        fighter->x = fighter->width / 2 + 1;
        fighter->dx = 0;
    }
    if(fighter->x > screenWidth - fighter->width / 2 - 1){
        fighter->x = screenWidth - fighter->width / 2 - 1;
        fighter->dx = 0;
    }

	// TO DO: write code to update y coordinate

	// draw the fighter at the new coordinate
    DrawFighter(fighter);
}

/* uncomment this code after defining tht Missile structure
void MoveMissile(Missile *missile, int screenWidth, int screenHeight)
{
// Problem 3
// TO DO: complete this function

	// erase the missile at current coordinate

	// move the missile to upper direction (decrease y)

    // if the missile hits the top (y == 0)
	// 		deactivate the missile (set missile->active to FALSE (zero))

	// if the missile is still active, draw '!' at the new coordinate
}
*/