#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000


static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

static void sort(unsigned int indexes[], char sorted[], char letters[], unsigned int max_size){
    for (unsigned int i=0; i < max_size; i++){
        sorted[indexes[i]] = letters[i];
    }
}

unsigned int 
data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_size){
    unsigned int i = 0;
    FILE *file = fopen(path, "r");
    
    while(!feof(file)){
        fscanf(file,"%u \'%c\'\n",&indexes[i], &letters[i]);
        i++;

    }
    fclose(file);
    if(i > max_size){
        return max_size;
    }else{
        return i;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2){
        printf("Argumentos invalidos");
        exit(EXIT_FAILURE);
    }

    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length = data_from_file(argv[1], indexes, letters, MAX_SIZE);
    sort(indexes, sorted, letters, length);
    dump(sorted, length);

    return EXIT_SUCCESS;
}

