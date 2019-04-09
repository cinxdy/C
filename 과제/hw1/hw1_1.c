#include <stdio.h>


int main(){
    
int distance = 0;
int timeSpan = 0;
int speed = 0;

printf("Input distance (in Km): ");
scanf("%d",&distance);
printf("Input time span (in hour): ");
scanf("%d",&timeSpan);
speed = distance/timeSpan;
printf("Average speed is %d Km/h\n",speed);

return 0;

}