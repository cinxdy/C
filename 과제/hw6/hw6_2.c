#include <stdio.h>

#define WIDTH 5 
#define HEIGHT 4

void FillNumPuzzle(int puzzle[][WIDTH]);
//Fill puzzle with numbers from 0 to (WIDTH * HEIGHT – 1) 
//Zero represents the hole.
void DisplayNumPuzzle(int puzzle[][WIDTH]);
//Display all numbers in puzzle.
//Print blank spaces for zero.

void ShuffleNumPuzzle(int puzzle[][WIDTH]);
//Shuffle all numbers in puzzle.
void GetZeroPosition(int puzzle[][WIDTH], int *r, int *c);
//Find the coordinate of zero. Put the vertical coordinate in *r and the horizontal coordinate in *c.
//See the example code and result in the next pages.


int main(){

   int puzzle[HEIGHT][WIDTH]; 
   int i = 0;

    srand(time(NULL)); 
    FillNumPuzzle(puzzle);
    DisplayNumPuzzle(puzzle);
    for(i = 0; i < 3; i++){

        int hole_r = 0, hole_c = 0;
        ShuffleNumPuzzle(puzzle);
        GetZeroPosition(puzzle, &hole_r, &hole_c);
        printf("Hole position: row = %d, col = %d\n", hole_r, hole_c); 
        DisplayNumPuzzle(puzzle);
    }

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
