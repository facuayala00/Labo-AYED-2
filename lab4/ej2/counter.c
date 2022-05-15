#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void) {
    counter c = NULL;
    c = malloc(sizeof(counter));
    c->count = 0;
    return c;
}

void counter_inc(counter c) {
    c->count++;
}

bool counter_is_init(counter c) {
    bool b = c->count == 0;
    return b;
}

void counter_dec(counter c) {
    assert(!counter_is_init(c));
    c -> count--;
}

counter counter_copy(counter c) {
    counter c1 = NULL;
    c1 = malloc(sizeof(counter));
    c1 = c;
    return c1;
}

void counter_destroy(counter c) {
    free(c);
}
