#include <stdio.h>    /* printf(), scanf() */
#include <stdbool.h>  /* tipo bool         */

#include <assert.h>   /* assert() */

#define ARRAY_SIZE 10

struct max_min_result {
    int max_value;
    int min_value;
    unsigned int max_position;
    unsigned int min_position;
};

/*
struct max_min_result compute_max_min(int array[], unsigned int length)
{
    int j = 0;
    struct max_min_result result;
    assert(length > 0);
    array = array;
    struct max_min_result result = { 0, 0, 0, 0 };
    result.max_value = -99999999;
    result.min_value = 9999999;
    while (j < length){
        if(array[j] > result.max_value){
            result.max_value = array[j];
            //result.max_position = j;
        }else if (array[j] < result.min_value){
            result.min_value = array[j];
            //result.min_position = j;
        }
        j++;
    }
    return result;
}
*/

struct max_min_result compute_max_min(int array[], unsigned int length)
{
    assert(length > 0);
    array = array;
    struct max_min_result result = { 0, 0, 0, 0 };
    result.max_value = array[0];
    result.min_value = array[0];
    for (size_t i = 1; i < length; i++)
    {
        if(array[i] > result.max_value){
            result.max_value = array[i];
            result.max_position = i;
        }else if (array[i] < result.min_value){
            result.min_value = array[i];
            result.min_position = i;
        }
    }
    return result;
}

int pedirEntero(int x)
{
    int z;
    printf("Ingrese un valor para la posicion '%d': \n", x);
    scanf("%d", &z);
    return z;
}

void pedirArreglo(int a[], int tam)
{
    int i = 0;
    while (i < tam)
    {
        a[i] = pedirEntero(i);
        i ++;
    }
}

int main(void)
{
    //int array[ARRAY_SIZE] = { 4, -1, 5, 8, 9, 0, 3, 6, 0, 0 };
    int array[ARRAY_SIZE];
    pedirArreglo(array, ARRAY_SIZE);
    struct max_min_result result = compute_max_min(array, ARRAY_SIZE);
    printf("Maximo: %d\n", result.max_value);
    printf("Posicion del maximo: %u\n", result.max_position);
    printf("Minimo: %d\n", result.min_value);
    printf("Posicion del minimo: %u\n", result.min_position);
    return 0;
}

