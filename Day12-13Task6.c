//Day 12-13 Task6 by Stefan Markovski
#include <stdio.h>
 
void bubbleSort(int* array, unsigned int size){
    int i, j, temp;
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (*(array + j) < *(array + i)) {
                temp = *(array + i);
                *(array + i) = *(array + j);
                *(array + j) = temp;
            }
        }
    }
    for (i = 0; i < size; i++){
        printf("%d ", *(array + i));
    }
}
 
int main(){
    unsigned int size = 5;
    int arr[] = { 0, 23, 14, 12, -9 };
    bubbleSort(arr, size);
    return 0;
}