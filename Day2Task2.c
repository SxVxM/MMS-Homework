//XOR calculator by Stefan Markovski
#include <stdio.h>
//How to start from a terminal:
// gcc Day2Task2.c -o execute
// ./execute < numbers.txt (if the numbers are in a text file)

int main(){
    int a, b, c, out = 0;
    //Input number a
    //printf("XOR calculator. Enter values 0 or 1\nEnter the first number: ");
    scanf("%d", &a);
    //Input number b
    //printf("Enter the second number: ");
    scanf("%d", &b);
    //Input number c
    //printf("Enter the third number: ");
    scanf("%d", &c);
    //If the user entered numbers different from 0 or 1 display an error
    if((a < 0 || b < 0 || c < 0) || (a > 1 || b > 1 || c > 1)){
        printf("Invalid numbers. Please insert numbers 0 or 1\n");
        return 1;
    }else{
        //XOR calculation
        out = a ^ b ^ c; 
        //Output
        printf("XOR value is: %d\n", out);
        return 0;
    }
}