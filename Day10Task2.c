// Day 10 Task 2 attempt by Stefan Markovski
#include <stdio.h>
#include <stdint.h>
void swapBytes(uint16_t word){
    uint16_t key;
    for(int i = 0; i < 5; i++){
        word = key >> 15;
        key = (key << 1);
        key |= word;
    }
}
int main(){
    uint16_t num = 100;
    printf("%d", num);
    swapBytes(num);
    printf("%d", num);
    putchar('\n');
}