#include <stdio.h>


int main(){

    float distance = 0;
float timeSpan = 0;
float speed = 0;

printf("Input distance (in Km): ");
scanf("%f",&distance);
printf("Input time span (in hour): ");
scanf("%f",&timeSpan);
speed = distance/timeSpan;
printf("Average speed is %f Km/h\n",speed);

return 0;

}