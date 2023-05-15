#include <stdint.h>
#include "stats.h"
#include <stdio.h>

void analyze(const unsigned char data[],int size){
    unsigned char max=data[0];
    unsigned char min=data[0];
    unsigned char sum=0;

    for(int i=1;i<size;i++){
        if(data[i]>max) max=data[i];
        if(data[i]<min) min=data[i];
        sum+=data[i];
    }
    double avg=(double)sum/size;
    unsigned char median=data[size/2];

    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);
    printf("Mean: %.0f\n", avg);
    printf("Median: %d\n", median);
}
void sortData(unsigned char data[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                unsigned char temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}
void printData(const unsigned char data[], int size) {
    printf("Sorted Data: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}
int main() {
    unsigned char data[MAX_LENGTH] = {15, 6, 8, 12, 9, 4, 11, 3, 14, 10};
    int size = MAX_LENGTH;
    
    analyze(data, size);
    sortData(data, size);
    printData(data, size);
    
    return 0;
}