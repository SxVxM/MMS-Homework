//Bit count by Stefan Markovski
#include <stdio.h>
#include <stdint.h>

unsigned bitCount(uint32_t mask);

int main(){
    printf("Ones count: %u\n", bitCount(1));
    return 0;
}
unsigned bitCount(uint32_t mask){
    unsigned count = 0;
    for(int bit = 0; bit < sizeof(uint32_t) * __CHAR_BIT__; bit++){
        count += (mask | (1ULL<<bit)) >> bit;
    }
    return count;
}
