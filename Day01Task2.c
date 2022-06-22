//Vertical and Horizontal Cylinder Volume Calculator by Stefan Markovski 
#include <stdio.h>
#include <math.h>
#define PI 3.14

int main (){
    //Doubles to use for the calculations
    double R, H, L, Vol;

    //Input for the length of the cylinder
    printf("Insert L as cylinder length: ");
    scanf("%lf", &L);

    //Input for the radius of the cylinder
    printf("Insert R as cylinder radius: ");
    scanf("%lf", &R);

    //Input for the water height in the cylinder
    printf("Insert H as water height: ");
    scanf("%lf", &H);

    //Calculating the volume for the vertical cylinder
    Vol = PI * pow(R, 2) * H;
    printf("Calculated volume while the cylinder is vertical = %.3lf cubic meters\n", Vol);

    //Calculating the volume for the horizontal cylinder
    Vol = (acos((R - H) / R)*pow(R,2) - (R-H)*sqrt(2*R*H - pow(H,2))) * L;
    printf("Calculated volume while the cylinder is horizontal = %.3lf cubic meters\n", Vol);
    return 0;
}
