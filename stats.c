#include <stdint.h>
#include "stats.h"
#include <stdio.h>

//Function has array and size of array as functions parameters.Function return maximum of input array.
int find_maximum(const unsigned char data[],int size){
    unsigned char max=data[0];
    for(int i=1;i<size;i++){
        if(data[i]>max) max=data[i];
    }
    return max;
}

//Function has array and size of array as functions parameters.Function return minimum of input array.
int find_minimum(const unsigned char data[],int size){
    unsigned char min=data[0];
    for(int i=1;i<size;i++){
        if(data[i]<min) min=data[i];
    }
    return min;
}

//Function takes sorted array and size of array as functions parameters.Function return median of input array.
int  find_median(const unsigned char data[],int size){
    if (size % 2 == 0) {
        median = (data[size / 2 - 1] + data[size / 2]) / 2;
    } else {
        median = data[size / 2];
    }
    return median;
}

//Function has array and size of array as functions parameters.Function return mean of input array.
double find_mean(const unsigned char data[],int size){
    unsigned char sum=0;
    for(int i=0;i<size;i++){
        sum+=data[i];
    }
    double avg=(double)sum/size;
    return avg;
}

//Function has array and size of array as functions parameters.The return type is void.Function prints Maximum,Minimum,Mean and Median of sorted array taken as input.
void print_statistics(const unsigned char data[],int size){
    
    unsigned char sum=0;
    double avg=(double)sum/size;
    

    printf("Maximum: %d\n", find_maximum(data,size));
    printf("Minimum: %d\n", find_minimum(data,size));
    printf("Mean: %.0f\n", find_mean(data,size));
    printf("Median: %d\n", find_median(data,size));
}

//Function has array and size of array as functions parameters.Function prints elements of the inpur array from large to small.
void sortData(unsigned char data[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j] < data[j + 1]) {
                unsigned char temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}

//Function has array and size of array as functions parameters.Function return maximum of input array.
void print_array(const unsigned char data[], int size) {
    printf("Sorted Data: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}
int main() {
    unsigned char data[MAX_LENGTH] = {15, 6, 8, 12, 9, 4, 11, 3, 14, 10};
    int size = MAX_LENGTH;

    //function call to sort arrray data.
    sortData(data, size);
    
    //function call to print statistics.
    print_statistics(data, size);
    
    //function call to print array data.
    print_array(data, size);
    
    return 0;
}