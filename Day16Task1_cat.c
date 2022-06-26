//Day 16 Task 1 "cat function" by Stefan Markovski
//Ignore warnings when compiling
// USE: ./a.out + fileName 
#include <stdio.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdlib.h>

#define STDIN 0
#define STDOUT 1

void filecopy(int ifd, int ofd){
    int n;
    char buf[BUFSIZ];
    while ((n = read(ifd, buf, BUFSIZ)) > 0){
        if (write(ofd, buf, n) != n){
            printf("write error\n");
        }
    }
}
int main(int argc, char *argv[]){
    int fd;
    if (argc == 1){
        filecopy(STDIN, STDOUT);
    }else{
        while (--argc > 0){
            if ((fd = open(*++argv, O_RDONLY)) == -1){
                printf("can't open %s \n", *argv);
            }
            else{
                filecopy(fd, STDOUT);
                close(fd);
            }
        }
    }
    return 0;
}