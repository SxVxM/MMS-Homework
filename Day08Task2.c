//Day 8 Task 2 by Stefan Markovski
#include <stdio.h>

int doubleNum(int n){
    return 2*n;
}
int* map(int* arr, size_t n, int (*func)(int)){
    for(int i = 0; i < n; i++){
        arr[i] = (*func)(arr[i]);
    }
    return arr;
}
int main(){ 
    int nums[] = {3, 10, 5, 6};
    map(nums, 5, doubleNum);
    for(int i = 0; i < 5; i++){
        printf("%d", nums[i]);
    }
    putchar('\n');
    return 0;
}