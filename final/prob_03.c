#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>


void GetMeanStdev(float array[], int size, float *mean, float *stdev);

int main(){
    srand(time(NULL));
    int N=0;
    float* num=NULL;
    float x=0;
    float mean=0.0,stdev=0.0;

    printf("How many random numbers?\n ");
    scanf("%d",&N);
    
    num=(float*)malloc(N*sizeof(float));
    
    for(int i=0;i<N;i++){
        x= rand();
        num[i]=x;
        printf("%.2f ",num[i]);
        if((i+1)%10==0) printf("\n");
    }
    
    GetMeanStdev(num,N,&mean,&stdev);

    printf("\nmean = %f, stdev = %f\n",mean,stdev);

    printf("==== Standardizing ====\n");
    
    for(int i=0;i<N;i++){
        num[i]=(num[i]-mean)/stdev;
        printf("%.2f ",num[i]);
        if((i+1)%10==0) printf("\n");
    }

    GetMeanStdev(num,N,&mean,&stdev);

    printf("\nmean = %f, stdev = %f\n",mean,stdev);


}

void GetMeanStdev(float array[], int size, float *mean, float *stdev){
    *mean = 0.F;
    *stdev = 0.F;
    int i = 0;
    for(i = 0; i < size; i++){
        *mean += array[i];
        *stdev += array[i] * array[i];
    }
        *mean /= size;
        *stdev = sqrt(*stdev/size - *mean * *mean);
}