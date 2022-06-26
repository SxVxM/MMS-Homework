//Day 17 Task 3 by Stefan Markovski
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(){
    fflush(stdout);
    pid_t pid = fork();
    if(-1 == pid){
        perror("fork");
        exit(EXIT_FAILURE);
    }   
    if(0 == pid){
        //child process
        execl("ls", "ls", NULL);
    }else{
        //parent process
        int status;
        wait(&status);
        if(WIFEXITED(status)){
            int statusCode = WEXITSTATUS(status);
            if(statusCode == 0){
                wait(NULL);
                execlp("cal", "cal", NULL);
                exit(0);
            }
        }
    }
    return EXIT_SUCCESS;
}