#include <stdio.h>

void sorting(int list[],int size);

int main(){

    int list_a[5]={5,4,3,2,1};

    for(int i=0;i<5;i++)
        printf("list[%d]=%d\n",i,list_a[i]);

    sorting(list_a,5);

    for(int i=0;i<5;i++)
        printf("list[%d]=%d\n",i,list_a[i]);


}

void sorting(int list[],int size){

    int current = 0; // start of the unsorted list 

    for(current = 0; current < size - 1; current++){

        int smallest = 0; 
        int walk = 0;
        int tempData = 0;

        // location of the smallest element
        // variable to traverse the unsorted list // temporary variable for exchange
        // find the smallest in the unsorted list
        smallest = current;
        for(walk = current + 1; walk < size; walk++)
            if(list[walk] < list[smallest]) smallest = walk;
        // exchange the smallest with the first of unsorted list 
        tempData = list[current];
        list[current] = list[smallest];
        list[smallest] = tempData;
    }


}