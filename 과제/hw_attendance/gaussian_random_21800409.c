#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define BUFFER_SIZE 1000

float rand_buffer[BUFFER_SIZE];

void InitGaussianRandom();
float GetGaussianRandom(float mean, float stdev);
void GetMeanStdev(float array[], int size, float *mean, float *stdev);

int main(){
    float array[BUFFER_SIZE * 2];
    const int array_size = BUFFER_SIZE * 2;
    float mean = 0.F, stdev = 0.F;
    int i = 0;

    srand(time(NULL));
    InitGaussianRandom();
    // generate random numbers from Gaussian distribution with mean=50 and stdev=20
    for(i = 0; i < array_size; i++){
        array[i] = GetGaussianRandom(50, 20);
    }
    GetMeanStdev(array, array_size, &mean, &stdev);
    printf("mean = %f, stdev = %f\n", mean, stdev);
    return 0;
}

void InitGaussianRandom(){
    float mean=0.F,stdev=0.F;
    
    // fill the global variable 𝑟𝑎𝑛𝑑_𝑏𝑢𝑓𝑓𝑒𝑟 with random numbers
    // (use rand() without any modification)
    for(int i=0;i<BUFFER_SIZE;i++){
        rand_buffer[i]=rand();
    }
    // compute mean and stdev of the 𝑟𝑎𝑛𝑑_𝑏𝑢𝑓𝑓𝑒𝑟 (use GetMeanStdev())
    GetMeanStdev(rand_buffer,BUFFER_SIZE,&mean,&stdev);
    // for test, print mean and stdev of 𝑟𝑎𝑛𝑑_𝑏𝑢𝑓𝑓𝑒𝑟
    printf("before standardizing : mean=%f,stdev=%f\n",mean,stdev);

    // standardize random functions
    // replace all numbers 𝑥 in 𝑟𝑎𝑛𝑑_𝑏𝑢𝑓𝑓𝑒𝑟 with (𝑥 − 𝑚𝑒𝑎𝑛) / 𝑠𝑡𝑑𝑒𝑣
    for(int i=0;i<BUFFER_SIZE;i++){
        rand_buffer[i]=(rand_buffer[i]-mean)/stdev;
    }
    GetMeanStdev(rand_buffer,BUFFER_SIZE,&mean,&stdev);
    // for test, print mean and stdev of 𝑟𝑎𝑛𝑑_𝑏𝑢𝑓𝑓𝑒�
    printf("after standardizing : mean=%f,stdev=%f\n",mean,stdev);
 }


float GetGaussianRandom(float mean, float stdev){
    // randomly pick-up a number 𝑥 from 𝑟𝑎𝑛𝑑_𝑏𝑢𝑓𝑓𝑒𝑟 (use rand() % BUFFER_SIZE)
    float x=rand_buffer[rand() % BUFFER_SIZE];
    // scale and shift 𝑥 with 𝑚𝑒𝑎𝑛 and 𝑠𝑡𝑑𝑒𝑣 (𝑥 = 𝑥 ∗ 𝑠𝑡𝑑𝑒𝑣 + 𝑚𝑒𝑎𝑛)
    x = x * stdev + mean;
    // return 𝑥
    return x;
 }

void GetMeanStdev(float array[], int size, float *mean, float *stdev){
    int i = 0;
    *mean = 0.F;
    *stdev = 0.F;
    for(i = 0; i < size; i++){
        *mean += array[i];
        *stdev += array[i] * array[i];
    }
    if(size > 0){
        *mean /= size;
        *stdev = sqrt(*stdev/size - *mean * *mean);
    }
}