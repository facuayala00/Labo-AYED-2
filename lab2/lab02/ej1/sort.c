#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void insert(int a[], unsigned int i) {
    unsigned int j = i;
    while (j>0u && goes_before(a[j],a[j-1u])){
        swap(a,j-1u,j);
        --j;
    };
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        assert(array_is_sorted(a,i)); //invariante
        insert(a, i);
    };
}
