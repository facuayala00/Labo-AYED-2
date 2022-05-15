/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Maximum allowed length of the array */
#define MAX_SIZE 100000

int pedirEnteroAr(int x)
{
    int z;
    printf("Ingrese un valor para la posicion '%d': \n", x);
    scanf("%d", &z);
    return z;
}

unsigned int pedirArreglo(int array[],
           unsigned int max_size) {
    //your code here!!!
    unsigned int largo;
    printf("Ingrese el largo del array: \n");
    scanf("%u", &largo);
    for(unsigned int i = 0; i < largo && i < max_size; i++){
        array[i] = pedirEnteroAr(i);
    }
    return largo;
}

void imprimeArreglo(int a[], unsigned int length) {
    //your code here!!!!!
    printf("[");
    for(unsigned int i=0; i < length - 1; i++){
        printf("%d, ", a[i]);
    }
    printf("%d", a[length-1]);
    printf("]\n");
}


int main(void) {
    int array[MAX_SIZE];
    unsigned int length = pedirArreglo(array, MAX_SIZE);
    imprimeArreglo(array, length);
    
    return 0;
}
