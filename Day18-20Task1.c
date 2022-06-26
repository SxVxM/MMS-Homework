//Day 18-20 Task 1 by Stefan Markovski
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

int randint(int min, int max){
    return min + rand() % (max - min + 1);
}

char* randomName(char* name){
    unsigned index = 0;
    name[index++] = randint('A', 'Z');
    int n = 9;
    for (int i = 0; i < n; i++){
        name[index++] = randint('a', 'z');
    }
    name[index] = '\0';
    return name;
}

void *routine(void* arg){
    sleep(1);
    char Name[10];
    randomName(Name);
    printf("Name: %s\n", Name);
}

int main(){
    int N;
    printf("Enter how many threads you want to output(between 1 and 10): \n");
    scanf("%d", &N);
    if(N <= 0){
        fprintf(stderr, "Invalid number!\n");
        return EXIT_FAILURE;
    }else{
        srand(time(NULL));
        pthread_t pth[N];
        for (int i = 0; i < N; i++){
            if(pthread_create(&pth[i], NULL, routine, NULL)){
                perror("create");
                exit(EXIT_FAILURE);
            }
        }
        for (int i = 0; i < N; i++){
            if(pthread_join(pth[i], NULL)){
                perror("join");
                exit(EXIT_FAILURE);
            }
        }
        return EXIT_SUCCESS;
    }
}