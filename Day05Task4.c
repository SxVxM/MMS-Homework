// Day 5 Task 4 by Stefan Markovski
#include <stdio.h>
#include <math.h>

int quadEq(double A, double B, double C, double* X1, double* X2);
int main(){
    double a, b, c, x1, x2;
    while(scanf("%lf %lf %lf", &a, &b, &c) != EOF){
        if(a != 0){
            quadEq(a, b, c, &x1, &x2);
            printf("X1 = %.2lf\nX2 = %.2lf\n", x1, x2);
        }else{
            printf("Number a must be different from 0");
        }
    }
    return 0;
}
int quadEq(double A, double B, double C, double* X1, double* X2){
    *X1 = (-B + sqrt(pow(B, 2) - 4*A*C)) / (2*A);
    *X2 = (-B - sqrt(pow(B, 2) - 4*A*C)) / (2*A);
}
