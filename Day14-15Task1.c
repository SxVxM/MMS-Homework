#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define COUNT 10

typedef int (*comparef_t)(const void*, const void*);

int compareTitleASC(const void*, const void*);

int randint(int, int);
double randReal(double, double);
char* randomName(char*);

typedef struct Book{
    char title[151];
    char author[101];
    unsigned pages;
    double price;
} Book;

void printBook(Book b){
    printf("Title: %25s ", b.title);
    printf("Author: %25s ", b.author);
    printf("Pages: %4u ", b.pages);
    printf("Price: %4.2lf\n", b.price);
}

int main(int argc, char **argv){
    srand(time(NULL));
    Book books[COUNT]; 
    for(int i = 0; i < COUNT; i++){
        randomName(books[i].author);
        randomName(books[i].title);
        books[i].pages = randint(5, 2000);
        books[i].price = randReal(1.0, 1000.0);
    }
    qsort(books, COUNT, sizeof(books[0]), compareTitleASC);

    for(int i = 0; i < COUNT; i++){
        printBook(books[i]);
    }
    FILE *file = fopen(argv[1], "wb");
    fwrite(books, sizeof(books), 1, file);
    fclose(file);
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
int compareTitleASC(const void* bp1, const void* bp2){
    Book* b1 = (Book*)bp1;
    Book* b2 = (Book*)bp2;
    return strcmp(b1->title, b2->title);
}