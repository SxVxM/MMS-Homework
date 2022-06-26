//Day 16 Task 1 "head function" by Stefan Markovski
// USE: ./a.out + fileName + number of lines
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    FILE *fp;
    char *line = NULL;
    int len = 0, cnt = 0;    
    if( argc < 3){
        printf("Too few arguments\n");
        printf("Please use: ./a.out + fileName + number of lines.\n");
        return -1;
    }
    fp = fopen(argv[1],"r");
    if( fp == NULL ){
        printf("%s cannot open!\n",argv[1]);
        return 1;   
    }
    while(getline(&line, &len, fp) != -1){
        cnt++;
        if (cnt > atoi(argv[2])){
            break;
        }
        printf("%s",line); fflush(stdout);
    }
    fclose(fp);
    return 0;
}