// Day 11 Task 1 by Stefan Markovski
#include <stdio.h>
#define MAX(x, y, z) ((x) > (y) ? ((x) > (z) ? (x) : (z)) : ((y) > (z) ? (y) : (z)))
#define MIN(x, y, z) ((x) < (y) ? ((x) < (z) ? (x) : (z)) : ((y) < (z) ? (y) : (z)))

#define SETBIT(p, n) ((p) |= ((1) << (n)))
#define CLEARBIT(p, n) ((p) &= ~((1) << (n)))
#define INVERSEBIT(p, n) ((p) ^= ((1) << (n)))
#define CHECKBIT(p,n) (((p) & ((1) << (n))) >> (n))

#define SWAP(a, b) (a ^= b ^= a ^= b)

int main(){
    int x = 5, y = 12, z = 4;
    int a = 13, b = 24;
    int p = 11, n = 2;
    putchar('\n');
    printf("From the numbers %d, %d, %d. The max number is: %d\n", x, y, z, MAX(x,y,z));
    printf("From the numbers %d, %d, %d. The min number is: %d\n", x, y, z, MIN(x,y,z));
    putchar('\n');

    printf("Number = %d\n", p);
    SETBIT(p, n);
    printf("After setting bit %d, number = %d\n", n, p);
    printf("Check bit %d in number %d = %d\n", n, p, CHECKBIT(p, n));
    CLEARBIT(p, n);
    printf("After clearing bit %d, number = %d\n", n, p);
    printf("Check bit %d in number %d = %d\n", n, p, CHECKBIT(p, n));
    INVERSEBIT(p, n);
    printf("After inversing bit %d, number = %d\n", n, p);
    printf("Check bit %d in number %d = %d\n", n, p, CHECKBIT(p, n));
    putchar('\n');

    printf("Numbers to swap: %d, %d\n", a, b);
    SWAP(a, b);
    printf("Swapped numbers: %d, %d\n", a, b);
    putchar('\n');
    return 0;
}