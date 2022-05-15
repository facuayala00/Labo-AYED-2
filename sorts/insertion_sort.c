#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

//Funcion que nos permite intercambiar entre si los elementos de un arreglo
void swap(int a[], int i, int j){ 
    int aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}


//Funcion que inserta un elemento del arreglo en la posicion del anterior elemento si este es mayor.
static void insert(int a[], unsigned int i) {
    unsigned int j = i;
    while (j>0u && a[j] < a[j-1u]){
        swap(a,j-1u,j);
        j--;
    }
}

//Funcion que ejecuta la funcion insert n veces donde n es la longitud del arreglo 
void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        insert(a, i);
    }
    printf("[");
    for(unsigned int i = 0u; i < length; i++){
        printf(" %d ", a[i]);
    }
    printf("]\n");
}

int main(){
    int arr [] = {90,80,-11,-11,0,50,20};
    insertion_sort(arr, 7);
    return 0;
}