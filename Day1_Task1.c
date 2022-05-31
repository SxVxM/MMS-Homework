//Body Mass Index Calculation with Old and New Formula by Stefan Markovski
#include <stdio.h>
#include <math.h>

int main(){
    //Doubles to use for input
    double weight, height, BMI;

    //Input for the weight
    printf("Old Formula for Calculating Body Mass \nEnter weight in kilograms: ");
    scanf("%lf", &weight);

    //Input for the height
    printf("Enter height in meters: ");
    scanf("%lf", &height);

    //Do the calculation
    BMI = weight / (pow(height, 2));

    //Display result with old formula
    printf("Calculated Body Mass Index with Old Formula = %.2lf\n", BMI);

    //Calculate new formula
    BMI = 1.3 * (weight / (pow(height, 2.5)));

    //Display result with new formula
    printf("Calculated Body Mass Index with New Formula = %.2lf\n", BMI);
    return 0;
}