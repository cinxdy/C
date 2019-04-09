#include <stdio.h>

void DrawBar(int length, char c);


int main(){
    int i = 0;
    int x = 0;
    char c=0;
    
    //input character
    printf("Input numbers (-999) to stop: ");

    for(i = 0; x != -999; i++){
        scanf("%d", &x);
        if(x != -999)
            DrawBar(x,'#');
    } 

    return 0;
}

void DrawBar(int length, char c){
    int i =0;
    for(i=0;i<length;i++){
        printf("%c",c);
    }
    printf("\n");
}