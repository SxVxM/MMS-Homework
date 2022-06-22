// Day 9 task 3 by Stefan Markovski
#include <stdio.h>

int binSearch(int* arr, size_t n, int key){
    int mid = n / 2;
    if(arr[mid] > key){
        return binSearch(arr, n-(n/2), key);
    }
    else if(arr[mid] < key){
        return binSearch(arr, n+(n/2), key);
    }
    else if(arr[mid] == key){
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