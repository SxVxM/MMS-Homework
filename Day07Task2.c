//Day 7 Task 2 by Stefan Markovski
#include <stdio.h>
#define ARRSIZE 4

unsigned sumArrayDigits(const int* arr, size_t n){
    int sum = 0, remainder;
    int temp;
    for(int i = 0; i < n; i++){
        temp = arr[i];
        while(temp != 0){
            remainder = temp % 10;
            sum = sum + remainder;
            temp = temp/10;
        }
    }
    return sum;
}

int main(){
    int arr[ARRSIZE] = {12, 34, 5, 70};
    printf("Sum = %d\n", sumArrayDigits(arr, ARRSIZE));
    return 0;
}