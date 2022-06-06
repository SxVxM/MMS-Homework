//Float vs Double comparison by Stefan Markovski
#include <stdio.h>

int main(){
    float x;
    double z;
    //Input for the float
    printf("Enter a number (this will be a float):\n");
    scanf("%f", &x);
    //Input for the double
    printf("Enter the same number (this will be a double):\n");
    scanf("%lf", &z);
    //Output 
    printf("Comparing both numbers:\n");
    printf("Float number = %20.18f\n", x);
    printf("Double number = %20.18f\n", z);
    return 0;
}