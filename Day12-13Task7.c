// Day 12-13 Task 7 by Stefan Markovski
#include <stdio.h>

unsigned int binSearch(unsigned int* arr, unsigned int n, unsigned int value){
    int mid = n / 2;
    if(arr[mid] > value){
        return binSearch(arr, n-(n/2), value);
    }
    else if(arr[mid] < value){
        return binSearch(arr, n+(n/2), value);
    }
    else if(arr[mid] == value){
        return mid;
    }else{
        return -1;
    }
}
int main(){
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    int x;
    printf("Enter a value you are looking for: ");
    scanf("%d", &x);
    printf("Value in the array at index: %d\n", binSearch(arr, 10, x));
}