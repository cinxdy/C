#include<stdio.h>

int main(){

    int start[2]={0};
    int end[2]={0};
    int during[2]={0};
    
    printf("start time? (hh mm):\n");
    scanf("%d %d",&start[0],&start[1]);
    printf("end time? (hh mm):\n");
    scanf("%d %d",&end[0],&end[1]);
    
    for(int i=0;i<2;i++)
        during[i] = end[i] - start[i];
    
    if(during[1]<0) {
        during[0]--;
        during[1]+=60;
    }
    else if(during[1]>=60){
        during[0]++;
        during[1]-=60;
    }

    if(during[0]<0) printf("ERROR!\n");
    
    printf("during is %d:%d\n", during[0],during[1]);
    
}