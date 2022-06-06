// Day 5 Task 2 by Stefan Markovski
#include <stdio.h>
#include <math.h>

int triangle(double A, double B, double C, double* P, double* S);
int main(){
    double a, b, c, p, s;
    while(scanf("%lf %lf %lf", &a, &b, &c) != EOF){
        if(a <= 0 || b <= 0 || c <= 0){
            printf("Invalid numbers\n");
        }else{
            triangle(a, b, c, &p, &s);
            printf("P = %.2lf S = %.2lf\n", p, s);
        }
    }
    return 0;
}
int triangle(double A, double B, double C, double* P, double* S){
    *P = A + B + C;
    double q = (A+B+C)/2;
    *S = sqrt(q * (q - A) * (q - B) * (q - C));
}