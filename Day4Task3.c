//Day 4 Task 3 by Stefan Markovski
#include <stdio.h>

int convert(int num, int base){
    if(num == 0 || base == 0){
        return num;
    }else{
        return(num % base) + 10 * convert(num / base, base);
    }
}
int main(){
    int input;
    printf("Enter a decimal number between 1 and 1000 and you will get it's value for all number bases from 2 to 10.\n");
    while(scanf("%d", &input) != EOF){
        if(input >= 0 && input <= 1000){
            for(int i = 2; i <= 10; i++){
                printf("%d is %d base(%d)\n", input, convert(input,i), i);
            }
        }else{
            printf("Invalid number\n");
        }
        printf("Try another number:\n");
    }
    return 0;
}