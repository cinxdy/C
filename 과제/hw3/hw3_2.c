#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    //랜덤 숫자를 세개 만들기
    int a=0, b=0, guess=0, answer=0;
    char op = 0;
    char operator[5] = "+-*/";

    srand(time(NULL));

    while(1){
        a = rand()%10+1;
        op = operator[rand()%4];
        b = rand()%10+1;

        //문제를 출력
        printf("%d %c %d = ",a,op,b);
        //추측값을 받음
        scanf("%d",&guess);

        //정답을 구하기
            //더하기
            if( op == '+' ) {
                answer = a+b;
            }

            //빼기
            else if( op == '-' ) {
                answer = a-b;
            }

            //곱하기
            else if( op == '*' ) {
                answer = a*b;
            }

            //나누기
            else if( op == '/' ) {
                answer = a/b;
            }



        //정답에 대해 메세지 출력하기
            //입력값이 -999면 끝냄
            if(guess == -999){
                printf("Bye!\n");
                break;
            }
            //정답이면 정답 메세지 출력
            else if(answer == guess) { 
                printf("Correct! Your are genius!\n");
            }
            //오답이면 오답 메세지 출력
            else {
                printf("The correct answer is %d. Try again!\n",answer);
            }  
    }
    return 0;
}