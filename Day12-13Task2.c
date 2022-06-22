// Day 12-13 Task 2 by Stefan Markovski
#include<stdio.h>
 
int getStringLength(char*);
void reverseString(char*);
 
int main(){
    char string[100] = {"MMS C Camp 15"};
    printf("String to reverse: %s\n", string);
    reverseString(string);
    printf("Reverse of the string is \"%s\".\n", string);
    return 0;
}
void reverseString(char *ptr){
    int length, c;
    char *begin, *end, temp;
    length = getStringLength(ptr);
    begin  = ptr;
    end    = ptr;
    for (c = 0; c < length - 1; c++){
        end++;
    }
    for (c = 0; c < length/2; c++){        
        temp   = *end;
        *end   = *begin;
        *begin = temp;
        begin++;
        end--;
    }
}
int getStringLength(char *ptr){
    int c = 0;
    while(*(ptr + c) != '\0'){
        c++;
    }
    return c;
}