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
    char* res = NULL;
    const size_t str_length = string_length(str); //no se va a modificar nunca por lo q agrego const
    const size_t c_count = string_ocurrence_count(str, c); //Modularizamos
    //res = (char*)malloc(sizeof(char) * (str_length +1u));
    res = malloc(sizeof(*res) * (str_length +1u)); //Segun google es mala practica hacer el cast
    return res;
}


size_t string_length(const char *str)
{

}