#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void swap(int a[], int i, int j){ 
    int aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}

static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    unsigned int piv = izq;
    unsigned int i=izq+1u,j=der;
    while (i <= j){
        if(a[i] <= a[piv]){
            i = i+1u;
        }else if(a[piv] >= a[piv]){
            j = j-1u;
        }else if(a[i] > a[piv] && a[j] < a[piv]){
            swap(a,i,j);
        }
    }
    swap(a,piv,j);
    piv = j;
    return piv;
}


static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    if (der > izq){
        int piv = partition(a, izq, der);
        if (piv > 0){
            quick_sort_rec(a, izq, piv - 1);
        }
        quick_sort_rec(a, piv + 1, der);
    }
}


void quick_sort(int a[], unsigned int length){
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
    printf("[");
    for(unsigned int i = 0u; i < length; i++){
        printf(" %d ", a[i]);
    }
    printf("]\n");
}


int main(){
    int arr [] = {90,80,-11,-11,0,50,20};
    quick_sort(arr, 7);
    return 0;
}
