// Day 5 Task 3 by Stefan Markovski
#include <stdio.h>

int rectangle(double A, double B, double* P, double* S);
int main(){
    double a, b, p, s;
    while(scanf("%lf %lf", &a, &b) != EOF){
        if(a <= 0 || b <= 0){
            printf("Invalid numbers\n");
        }else{
            rectangle(a, b, &p, &s);
            printf("P = %.2lf S = %.2lf\n", p, s);
        }
    }
    return 0;
}
int rectangle(double A, double B, double* P, double* S){
    *P = 2*A + 2*B;
    *S = A * B;
}