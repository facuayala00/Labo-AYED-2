#include <assert.h>
#include "mybool.h"
#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h"

unsigned int array_from_file(int array[],   
           unsigned int max_size,
           const char *filepath) {
    //your code here!!!
    FILE *file;
    file = fopen(filepath, "r");
    unsigned int largo;
    if (file != NULL){
        fscanf(file, "%u", &largo);
        printf("%u\n", largo);
        for(unsigned int i = 0; i < largo && i < max_size; i++){
            fscanf(file, "%d", &array[i]);

        }
        fclose(file);
    }else{
        printf("Error Reading File\n");
        exit (0);
    
    }
    if (largo >= max_size){
        return max_size;
    }
    return largo;
}

void array_dump(int a[], unsigned int length) {
    //your code here!!!!!
    if(length == 0){
        printf("[]\n");
    }
    else{
        printf("[");
        for(unsigned int i=0; i < length - 1; i++){
            printf("%d, ", a[i]);
    }
    printf("%d", a[length-1]);
    printf("]\n");
        
    }
}

mybool array_is_sorted(int a[], unsigned int length){
    mybool res = true;
    for(unsigned int i=0; i < length - 1; i++){
        res = res && (a[i] <= a[i + 1]);
    }
    return res;
}

