#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */
#include <assert.h>

pair_t pair_new(int x, int y){
    pair_t p;
    p.fst = x;
    p.snd = y;
    assert(p.fst == x && p.snd == y);
    return p;
}

int pair_first(pair_t p){
    int fst;
    assert(fst == p.fst);
    return fst = p.fst;
}

int pair_second(pair_t p){
    int snd;
    assert(snd == p.snd);
    return snd = p.snd;
}

pair_t pair_swapped(pair_t p){
    pair_t d;
    d.fst = p.snd;
    d.snd = p.fst;
    assert(d.fst == p.snd && d.snd == p.fst);
    return d;
}

pair_t pair_destroy(pair_t p){
    return p;
}

/* 
 *¿La implementación logra encapsulamiento? ¿Por qué sí? ¿Por qué no?
 * La implementación no logra encapsulamiento porque para acceder al primer y/o segundo elemento puedo hacer uso de las operacione p.fst y p.snd
 */