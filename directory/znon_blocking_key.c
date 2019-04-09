#include <stdio.h>

#include "Console.h"

//gcc non_blocking_key.c Console.c -D_MAC

int main(){
    int i=0,t=0;
    int delay = 100000;
    char key = 0;

    clrscr();

    printf("Press enter to start :");
	getchar();
    
    while(1){
        if(kbhit()){
            if(key = _getch() == 't'){
                printf("Bye!");
                break;
            }
        }

        if(t % delay == 0)
            printf("%d\n",i++);

        t++;
    }
    
    return 0;
}