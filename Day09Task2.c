// Day 9 task 2 by Stefan Markovski
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define COUNT 10

int comparePriceASC(const void*, const void*);

int randint(int, int);
double randReal(double, double);
char* randomName(char*);

void* lsearch(const void* key, void *base, size_t nitems, size_t size, int(*compare)(const void*, const void*)){
    for(int i = 0; i < nitems; i++){
        if(compare(key, base + i * size) == 0){
            return base + i * size;
        }
    }
    return NULL;
}

typedef struct Book{
    char title[151];
    char author[101];
    unsigned pages;
    double price;
} Book;

void printBook(Book *b){
    printf("Title: %25s ", b->title);
    printf("Author: %25s ", b->author);
    printf("Pages: %4u ", b->pages);
    printf("Price: %4.2lf\n", b->price);
}

int main(){
    srand(time(NULL));
    Book books[COUNT]; 
    int option;
    for(int i = 0; i < COUNT; i++){
        randomName(books[i].author);
        randomName(books[i].title);
        books[i].pages = randint(18, 22);
        books[i].price = randReal(20.48, 20.52);
    }

    Book key = {.author="Vazov", .price=20.50, .pages=20, .title="PodIgoto"};
    Book *element = lsearch(&key, books, COUNT, sizeof(*books), comparePriceASC);
    if(!element){
        printf("Not Found!\n");
    }else{
        printf("Found!\n");
        printBook(element);
    }
    return 0;
}

int randint(int min, int max){
    return min + rand() % (max - min + 1);
}
double randReal(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}
char* randomName(char* name){
    unsigned index = 0;
    name[index++] = randint('A', 'Z');
    int n = randint(5, 10);
    for (int i = 0; i < n; i++){
        name[index++] = randint('a', 'z');
    }
    name[index++] = ' ';
    n = randint(5, 10);
    name[index++] = randint('A', 'Z');
    for (int i = 0; i < n; i++){
        name[index++] = randint('a', 'z');
    }
    name[index] = '\0';
    return name;
}

int comparePriceASC(const void* bp1, const void* bp2){
    Book* b1 = (Book*)bp1;
    Book* b2 = (Book*)bp2;
    if(fabs(b1->price - b2->price) < 0.001){
        return 0;
    }
    else if(b1 -> price > b2->price){
        return 1;
    }
    return -1;
}