//Calculator for sorting the biggest number by Stefan Markovski
#include <stdio.h>
#include <limits.h>
//How to start from a terminal:
// gcc Day2Task1.c -o execute
// ./execute < numbers.txt (if the numbers are in a text file)

int main(){
    int num, maxNum = INT_MIN;
    while(scanf("%d", &num) != -1)
    {
        if(num > maxNum){
            maxNum = num;
        }
    }
    printf("The largest number is: %d\n", maxNum);
    return 0;
}
