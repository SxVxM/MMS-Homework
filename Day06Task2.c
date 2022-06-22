//Day 6 Task 2 by Stefan Markovski
#include <stdio.h>
#define n 20 //number of iterations

int main(){
    double sum = 0, fact = 1, pow = 1, input, x;

    printf("Enter an angle in degrees: ");
    scanf("%lf", &input);

    x = (3.1415926535897931 * input) / 180.0;//Get value in radians

    for(int i = 0; i <= n; i++){
        fact = 1.0;
        pow = 1.0;
        for(int j = 1; j <= 2*i+1; j++){
            fact *= j;
            pow *= x;
        }
        sum += ((i % 2? - 1.0 : 1.0)/fact)*pow;
    }
    printf("sin(%.0f) = %f\n", input, sum);
    return 0;
}