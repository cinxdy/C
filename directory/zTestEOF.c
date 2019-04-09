#include <stdio.h>

int main(){

  int sum = 0, x= 0;
  int testEOF = 0;
  printf("Enter your numbers <EOF> to stop.\n"); //which code is -1

  while(1){
    testEOF = scanf("%d",&x);
    if(testEOF==EOF) break;
      sum += x;
  }

  printf("Total: %d\n", sum);
  return 0;
}
