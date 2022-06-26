//Day 17 Task 4 by Stefan Markovski
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(){
    pid_t pid = fork();
    if(-1 == pid){
        perror("fork");
        exit(EXIT_FAILURE);
    }   
    if(0 == pid){
        //child process
        execl("ls", "l", NULL);
    }else{
        //parent process
        int status;
        wait(&status);
        if(WIFEXITED(status)){
            int statusCode = WEXITSTATUS(status);
            if(statusCode == 0){
                exit(EXIT_FAILURE);
            }else{
                execlp("cal", "cal", NULL);
            }
        }
        wait(NULL);
    }
    return EXIT_SUCCESS;
}