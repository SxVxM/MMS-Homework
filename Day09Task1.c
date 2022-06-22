// Day 9 task 1 by Stefan Markovski
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define COUNT 10

typedef int (*comparef_t)(const void*, const void*);

int compareTitleASC(const void*, const void*);
int compareAuthorASC(const void*, const void*);
int comparePagesASC(const void*, const void*);
int comparePriceASC(const void*, const void*);
int compareTitleDESC(const void*, const void*);
int compareAuthorDESC(const void*, const void*);
int comparePagesDESC(const void*, const void*);
int comparePriceDESC(const void*, const void*);

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

int main(){
    srand(time(NULL));
    Book books[COUNT]; 
    int option;
    comparef_t compfunc[] = {
        compareTitleASC,
        compareAuthorASC,
        comparePagesASC,
        comparePriceASC,
        compareTitleDESC,
        compareAuthorDESC,
        comparePagesDESC,
        comparePriceDESC
    };
    for(int i = 0; i < COUNT; i++){
        randomName(books[i].author);
        randomName(books[i].title);
        books[i].pages = randint(5, 2000);
        books[i].price = randReal(1.0, 1000.0);
    }
    printf("Pick a number from 0 to 7 to sort:\n");
    scanf("%d", &option);
    qsort(books, COUNT, sizeof(books[0]), compfunc[option]);

    for(int i = 0; i < COUNT; i++){
        printBook(books[i]);
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
int compareTitleASC(const void* bp1, const void* bp2){
    Book* b1 = (Book*)bp1;
    Book* b2 = (Book*)bp2;
    return strcmp(b1->title, b2->title);
}
int compareAuthorASC(const void* bp1, const void* bp2){
    Book* b1 = (Book*)bp1;
    Book* b2 = (Book*)bp2;
    return strcmp(b1->author, b2->author);
}
int comparePagesASC(const void* bp1, const void* bp2){
    Book* b1 = (Book*)bp1;
    Book* b2 = (Book*)bp2;
    return b1->pages - b2->pages;
}
int comparePriceASC(const void* bp1, const void* bp2){
    Book* b1 = (Book*)bp1;
    Book* b2 = (Book*)bp2;
    if(fabs(b1->price - b2->price) < 0.0001){
        return 0;
    }
    else if(b1 -> price > b2->price){
        return 1;
    }
    return -1;
}
int compareTitleDESC(const void* bp1, const void* bp2){
    Book* b1 = (Book*)bp1;
    Book* b2 = (Book*)bp2;
    return strcmp(b2->title, b1->title);
}
int compareAuthorDESC(const void* bp1, const void* bp2){
    Book* b1 = (Book*)bp1;
    Book* b2 = (Book*)bp2;
    return strcmp(b2->author, b1->author);
}
int comparePagesDESC(const void* bp1, const void* bp2){
    Book* b1 = (Book*)bp1;
    Book* b2 = (Book*)bp2;
    return b2->pages - b1->pages;
}
int comparePriceDESC(const void* bp1, const void* bp2){
    Book* b1 = (Book*)bp1;
    Book* b2 = (Book*)bp2;
    if(fabs(b1->price - b2->price) < 0.0001){
        return 0;
    }
    else if(b1 -> price < b2->price){
        return 1;
    }
    return -1;
}