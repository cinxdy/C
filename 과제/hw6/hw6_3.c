#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Console.h"

#define WIDTH 5
#define HEIGHT 4

void FillNumPuzzle(int puzzle[][WIDTH]);
void DisplayNumPuzzle(int puzzle[][WIDTH]);
void ShuffleNumPuzzle(int puzzle[][WIDTH]);
void GetZeroPosition(int puzzle[][WIDTH], int *r, int *c);

int main(){
    int puzzle[HEIGHT][WIDTH];
    int i = 0;
    int screenWidth = getWindowWidth();
    int screenHeight = getWindowHeight();
    
    clrscr();
    srand(time(NULL));

    FillNumPuzzle(puzzle);
    ShuffleNumPuzzle(puzzle);

    char key = 0;
    int cont = 1;
    int hole_r = 0, hole_c = 0;

    GetZeroPosition(puzzle, &hole_r, &hole_c);
    while(cont){
        gotoxy(1, 1);
        DisplayNumPuzzle(puzzle);

        gotoxy(screenWidth, 1);
        key = _getch();
        switch(key){
            case 'j':       // left
                if(hole_c < WIDTH - 1){
                    puzzle[hole_r][hole_c] = puzzle[hole_r][hole_c + 1];
                    hole_c++;
                    puzzle[hole_r][hole_c] = 0;
                }
                break;

            case 'l':       // right
                if(hole_c > 0){
                    puzzle[hole_r][hole_c] = puzzle[hole_r][hole_c - 1];
                    hole_c--;
                    puzzle[hole_r][hole_c] = 0;
                }
                break;                
            
            case 'i':       // up
            	if(hole_r < HEIGHT - 1){
                    puzzle[hole_r][hole_c] = puzzle[hole_r + 1][hole_c];
                    hole_r++;
                    puzzle[hole_r][hole_c] = 0;
                }
                break;
            
            case 'k':       // down
            	if(hole_r > 0){
                    puzzle[hole_r][hole_c] = puzzle[hole_r - 1][hole_c];
                    hole_r--;
                    puzzle[hole_r][hole_c] = 0;
                }
            	break;
            
            case 'q':
                clrscr();
                cont = 0;
                break;
        }
    }

    printf("Bye!\n");

    return 0;
}


void FillNumPuzzle(int puzzle[][WIDTH]){
    int k=0;
    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
            puzzle[i][j]=k;
            k++;
        }
    }
}

void DisplayNumPuzzle(int puzzle[][WIDTH]){
    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
            if(puzzle[i][j]==0)
                printf("   ");
            else
            printf("%2d ",puzzle[i][j]);
        }
        printf("\n");
    }
}

void ShuffleNumPuzzle(int puzzle[][WIDTH]){
    int temp=0;
    //Repeat on i from 0 to HEIGHT - 1 
    for(int i=0;i<HEIGHT;i++){
        //Repeat on j from 0 to WIDTH - 1
        for(int j=0;j<WIDTH;j++){
            //Randomly select i2 in [0, HEIGHT) and j2 in [0, WIDTH)
            int i2=rand()%HEIGHT;
            int j2=rand()%WIDTH;

            //Swap puzzle[i][j] and puzzle[i2][j2]
            temp=puzzle[i][j];
            puzzle[i][j]=puzzle[i2][j2];
            puzzle[i2][j2]=temp;
        }
    }
}

void GetZeroPosition(int puzzle[][WIDTH], int *r, int *c){
    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
            if(puzzle[i][j]==0){
                *r=i;
                *c=j;
            }
        }
    }
}
