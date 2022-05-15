/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y){
    return (*x).rank <= (*y).rank;
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}

void swap(player_t atp[],int x, int y){
    player_t aux = atp[x];
    atp[x] = atp[y];
    atp[y] = aux;
}

static unsigned int partition(player_t atp[], unsigned int izq, unsigned int der) {
    int ppiv = izq, i = izq + 1u, d = der;
    while ( i <= d){
        if (goes_before(atp[i],atp[ppiv])){
            i++;
        }else if (goes_before(atp[ppiv],atp[d])){
            d--;
        }else if(goes_before(atp[d],atp[ppiv]) && goes_before(atp[d],atp[ppiv])){
            swap(atp,i,d);
            i++;
            d--;
        }
        

    }
    
    swap(atp,ppiv,d);
    ppiv = d;
   return ppiv;
}


static void quick_sort_rec(player_t atp[], unsigned int izq, unsigned int der) {
    int ppiv;
    if (der > izq){
        
        ppiv = partition(atp, izq, der);
        if (ppiv > 0){
            quick_sort_rec(atp,izq,ppiv-1);
            quick_sort_rec(atp,ppiv+1,der);
        }else{
            quick_sort_rec(atp,izq,ppiv);
            quick_sort_rec(atp,ppiv+1,der);
        }

    }
}


void sort(player_t atp[], unsigned int length) {
    quick_sort_rec(atp, 0, 0 == length ? 0 : length-1);
}