//Square root without math.h by Stefan Markovski
#include <stdio.h>

double rootFunc(int number){
    int i = 0;
    double root = 1;
    while(1){
        i = i + 1;
        root = (number / root + root) / 2;
        if(i == number + 1){
            break;
        }
    }
    return root;
}
int main(){
    int num;
    printf("Enter a number: \n");
    while(scanf("%d", &num) != EOF){
        if(num > 0){
            printf("SQRT = %.2f\n", rootFunc(num));
        }else{
            printf("Invalid number!\nTry again\n");
        }
    }
    return 0;
}
