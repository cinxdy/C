#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


#define BUFFER_SIZE 1000
float rand_buffer[BUFFER_SIZE];
int rand_idx = BUFFER_SIZE;


void GetMeanStdev(float array[], int size, float *mean, float *stdev);
void InitGaussianRandom();
float GetGaussianRandom(float mean, float stdev);

int main()
{
    float array[BUFFER_SIZE * 2];
    const int array_size = BUFFER_SIZE * 2;
    float mean = 0.F, stdev = 0.F;
    int i = 0;

    srand(time(NULL));

    InitGaussianRandom();

    for(i = 0; i < array_size; i++)
        array[i] = GetGaussianRandom(50, 20);

    GetMeanStdev(array, array_size, &mean, &stdev);

    printf("mean = %f, stdev = %f\n", mean, stdev);

    return 0;
}

void GetMeanStdev(float array[], int size, float *mean, float *stdev)
{
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

void InitGaussianRandom()
{
	// fill the global variable rand_buffer with random numbers
	// (use rand() without any modification)

	// compute mean and stdev of the rand_buffer (use GetMeanStdev())

	// for test, print mean and stdev of rand_buffer

	// standardize random functions
	// replace all numbers x in rand_buffer with "x = (x-mean) / stdev;

	// for test, print mean and stdev of rand_buffer
}

float GetGaussianRandom(float mean, float stdev)
{
	// randomly pick-up a number x from rand_buffer (use rand() % BUFFER_SIZE)
	
	// scale and shift x using mean and stdev (x = x * stdev + mean)
	
   	// return x
}
