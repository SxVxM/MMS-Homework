//Day 5 Task 1 by Stefan Markovski
#include <stdio.h>

int main(){
    double a, b;
    char action;
    printf("Enter an eqiasion using +, -, *, /: \n");
    while(EOF){
        scanf("%lf", &a);
        scanf("%c", &action);
        scanf("%lf", &b);
        if(action == '+'){
            printf("%f\n", a + b);
        }
        else if(action == '-'){
            printf("%f\n", a - b);
        }
        else if(action == '*'){
            printf("%f\n", a * b);
        }
        else if(action == '/'){
            printf("%f\n", a / b);
        }else{
            printf("Invalid action!");
        }    
    }
    return 0;
}
