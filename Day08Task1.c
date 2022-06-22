//Day 8 Task 1 by Stefan Markovski

#include <stdio.h>
#include <string.h>
#define STRSIZE 20
int main(){
    char lenStr1[STRSIZE] = "Program";
    char lenStr2[STRSIZE] = {'P', 'r', 'o', 'g', 'r', 'a', 'm', '\0'};

    char cpyStr1[STRSIZE] = "MMS C camp 15";
    char cpyStr2[STRSIZE];
    char cpynStr[STRSIZE];

    char catStr1[STRSIZE] = "Hello, my name ";
    char catStr2[STRSIZE] = "is Stefan";
    char catnStr1[STRSIZE] = "Hello, my name ";
    char catnStr2[STRSIZE] = "is Stefan";

    char cmpStr1[STRSIZE] = "Hello World!";
    char cmpStr2[STRSIZE] = "Hello world!";
    int compareResult, compareResult2;

    char string[STRSIZE] = "Butterfly";
    char subString[STRSIZE] = "fly";
    char string2[STRSIZE] = "Butterfly";
    char subString2[STRSIZE] = "Fly";
    char *res, *res2;

    printf("Length of string 1 = %zu\n", strlen(lenStr1));
    printf("Length of string 2 = %zu\n", strlen(lenStr2));
    printf("Length of string 1 using strnlen = %zu\n", strnlen(lenStr1, STRSIZE));
    printf("Length of string 2 using strnlen = %zu\n", strnlen(lenStr2, STRSIZE));
    putchar('\n');

    strcpy(cpyStr2, cpyStr1);
    printf("Copy string output: %s\n", cpyStr2);
    strncpy(cpynStr, cpyStr1, 10);
    printf("Copy string output using strncpy: %s\n", cpynStr);
    putchar('\n');

    strcat(catStr1, catStr2);
    printf("Contcatenate function output: %s\n", catStr1);
    strncat(catnStr1, catnStr2, 7);
    printf("Contcatenate function output: %s\n", catnStr1);
    putchar('\n');

    compareResult = strcmp(cmpStr1, cmpStr2);
    printf("Comparing string 1 and string 2 result = %d\n", compareResult);
    compareResult2 = strncmp(cmpStr1, cmpStr2, 5);
    printf("Comparing string 1 and string 2 result = %d\n", compareResult2);
    putchar('\n');

    res = strstr(string, subString);
    printf("The substring is: %s\n", res);
    res2 = strstr(string2, subString2);
    printf("The substring is: %s\n", res2);

    return 0;
}