#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

static unsigned int min_pos_from(int a[], unsigned int i, unsigned int length) {
    unsigned int min_pos = i;
    for (unsigned int j = i + 1; j < length; ++j) {
        if (a[j] < a[min_pos]) {
            min_pos = j;
        }
    }
    return (min_pos);
}

void swap(int a[], unsigned int i, unsigned int j){ 
    unsigned int aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}

void selection_sort(int a[], unsigned int length) {
    for (unsigned int i = 0u; i < length; ++i) {
        unsigned int min_pos = min_pos_from(a, i, length);
        swap(a, i, min_pos);
    }
    printf("[");
    for(unsigned int i = 0u; i < length; i++){
        printf(" %d ", a[i]);
    }
    printf("]\n");

}


int main(){
    int arr [] = {90,80,-11,-11,0,50,20};
    selection_sort(arr, 7);
    return 0;
}
