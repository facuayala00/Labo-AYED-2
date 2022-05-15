#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */
#include <assert.h>

pair_t pair_new(int x, int y){
    pair_t p = NULL;
    p = malloc(sizeof(pair_t));
    p->fst = x;
    p->snd = y;
    return p;
}
/*
 * DESC: Creates a new pair with components (x, y)
 *
 * p = pair_new(x, y);
 *
 * POS: {p --> (x, y)}
 */

int pair_first(pair_t p){
    int fst = p->fst;
    assert(fst == p->fst);
    return fst;
    
}
/*
 * DESC: Returns the first component of p
 *
 * PRE: {p --> (x, y)}
 *
 *  fst = pair_first(p);
 *
 * POS: {fst == x}
 */

int pair_second(pair_t p){
    int snd = p->snd;
    assert(snd == p->snd);
    return snd;
}
/*
 * DESC: Returns the second component of p
 *
 * PRE: {p --> (x, y)}
 *
 *  snd = pair_second(p);
 *
 * POS: {snd == y}
 */

pair_t pair_swapped(pair_t p){
    pair_t d = NULL;
    d = malloc(sizeof(pair_t));
    d -> fst = p -> snd;
    d -> snd = p -> fst;
    assert(d->fst == p-> snd && d->snd == p-> fst);
    return d;
}
/*
 * DESC: Return a NEW pair with the components of p reversed
 *
 * PRE: {p --> (x, y)}
 *
 *  q = pair_swapped(p)
 *
 * POS: {q --> (y, x)}
 *
 */

pair_t pair_destroy(pair_t p){
    free(p);
    return NULL;
}
/*
 * DESC: Free memory if its necesary
 *
 */
