//Day 16 Task 1 "tail function" by Stefan Markovski
//Ignore warnings when compiling
//Use: ./a.out + fileName + number of lines
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void tail(int lines, char *file_name){
    struct stat file;
    int size = 0;
    char *ch = NULL;
    char *buf = NULL;
    FILE *fd = fopen(file_name, "r");
    if(fd == NULL){
        printf("Not able to open the file : %s\n", file_name);
    }
    fseek(fd, 0, SEEK_END);
    size = ftell(fd);
    --size;
    ch = (char *)malloc(2);
    buf = (char *)malloc(80 * lines);
    memset(buf, 0, 80 * lines);

    char * start = buf;
    *buf++ = '\0';

    while(size && lines){
        --size;
        fseek(fd, size , SEEK_SET);
        fread(ch, 1, 1, fd);
        *buf++ = *ch;
        if(*ch == '\n'){
            lines--;
        }
    }
    close(fd);
    while( start != buf){
        printf("%c", *buf--);
    }
    printf("\n");
    free(ch);
    free(buf);
}
int main(int argc, char **argv){
    if(argc != 3){
        printf("Run exe file_name no_of_lines\n");
        return (-1);
    }
    char *file = argv[1];
    tail(atoi(argv[2]), file);
    return 0;
}
