#include <stdio.h>
#include <stdlib.h>

#include "strfuncs.h"


static size_t string_ocurrence_count(const char* str, char c)
{
    const size_t str_length = string_length(str);
    size_t c_count = 0u;
    for(unsigned int i = 0; i < str_length; ++i)
    {
        if(str[i] == c)
        {
            ++c_count;
        }
    }
    return c_count;
}


char* string_filter(const char * str, char c)
{
    unsigned int i = 0, j = 0;
    char* res = NULL;
    const size_t str_length = string_length(str); //no se va a modificar nunca por lo q agrego const
    const size_t c_count = string_ocurrence_count(str, c); //Modularizamos
    res = malloc(sizeof(char) * (str_length - c_count + 1u));
    for(unsigned int k = 0; k < str_length - c_count + 1u; ++k){
        res[k]='\0';
    }
    while(str[i] != '\0'){
        if(str[i] != c){
            res[j] = str[i];
            j++;
        }
        i++;
    }
    //res = malloc(sizeof(*res) * (str_length +1u)); //Segun google es mala practica hacer el cast
    return res;
}


size_t string_length(const char *str)
{
    size_t length = 0;
    unsigned int i;
    for(i=0; str[i] != '\0'; i++){
        length++;
    }
    return length;
}