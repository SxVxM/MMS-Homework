//Day 10 Task 1 by Stefan Markovski
#include <stdio.h>

void bitsDisplay(int num){
    int i, k, mask;
    for(i = 31; i >= 0; i--){
        mask = 1 << i;
        k = num & mask;
        k == 0 ? printf("0") : printf("1");
    }
}
int main(){
    bitsDisplay(7);
    putchar('\n');
    return 0;
}