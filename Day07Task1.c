//Day 7 Task 1 by Stefan Markovski
#include <stdio.h>
#include <limits.h>
#define ARRSIZE 5
int secondMax(const int* arr, size_t n, int* secondMax){
    int i, max1;
    max1 = *secondMax = INT_MIN;
    for(i = 0; i < n; i++){
        if(arr[i] > max1){
            *secondMax = max1;
            max1 = arr[i];
        }
        else if(arr[i] > *secondMax && arr[i] < max1){
            *secondMax = arr[i];
        }
    }
    if(max1 == 0 && *secondMax == -2147483648){
        printf("Empty array.\n");
        return 1;
    }
    else if(*secondMax == -2147483648){
        printf("All elements in the array are the same.\n");
        return 1;
    }else{
        printf("Largest number is: ");
        return *secondMax;
    }
}
int main(){
    int arr[ARRSIZE] = {-2,3,-4,5,6};
    int secondMaxNum;
    printf("%d\n", secondMax(arr, ARRSIZE, &secondMaxNum));
    return 0;
}