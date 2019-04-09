#include <stdio.h>

#define WIDTH 5 
#define HEIGHT 4

void FillNumPuzzle(int puzzle[][WIDTH]);
//Fill puzzle with numbers from 0 to (WIDTH * HEIGHT – 1) 
//Zero represents the hole.
void DisplayNumPuzzle(int puzzle[][WIDTH]);
//Display all numbers in puzzle.
//Print blank spaces for zero.

int main(){

    int puzzle[HEIGHT][WIDTH];
    FillNumPuzzle(puzzle);
    DisplayNumPuzzle(puzzle);
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