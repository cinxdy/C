#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){

    int answer = 0;
    int guess = 1;
    srand(time(NULL));

    //정답을 정함
    answer = rand()%100 +1;
    //초기 메세지 출력
    printf("I selected a number between 1 and 100. Find it by guess.\n");

    //추측값과 정답이 맞을 때까지 반복
    while(1){
        printf("Input a number between 1 and 100:");
        scanf("%d",&guess);

        //추측값이 정답보다 작으면 작다고 출력
        if(guess<answer) {
            printf("%d is too small\n",guess);
        }
        
        //추측값이 정답보다 크면 크다고 출력
        else if (guess>answer) {
            printf("%d is too large\n",guess);
        }
        
        //추측값과 정답이 일치하면 성공 메세지를 출력하고 빠져나오기
        else if (guess == answer) {
        printf("Great! You got it. My number is %d!\n",guess);
        break;
        }
        
    }

    return 0;
}