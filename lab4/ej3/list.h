#ifndef _LIST_H
#define _LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//We ensure encapsulation by using a pointer to the struct _Node
typedef struct _Node * list;

typedef int list_elem;

//CONSTRUCTORS

list empty_list(void);
/*
 *Creates an empty list
 */

list addl(list l, list_elem e);
/*
 *Given a list and an element adds this element at the beginning of the list
 */


//OPERATIONS
bool is_empty(list l);
/*
 *Returns true if the list is empty.
 */

list_elem head(list l);
/*
 *Returns the first element of the list.
 *PRE: {!is_empty(list l)}
 */

list tail(list l);
/*
 *Returns the list without the first element.
 *PRE: {!is_empty(list l)}
 */

list addr(list l, list_elem e);
/*
 *Given a list and an element adds this element at the end of the list
 */
unsigned int length(list l);
/*
 *Returns the length of the list.
 */

list concat(list l, list l2);
/*
 *Adds at the end of the first list all the elements of the second list in the same order.
 */

list_elem index(list l, unsigned int n);
/*
 *Returns the nth element of the list
 *PRE: {length(list l) > n}
 */

list take(list l, unsigned int n);
/*
 *Returns the list only with the first n elements.
 *PRE: {length(list l) > n}
 */

list drop(list l, unsigned int i);
/*
 *Returns the list without the first n elements.
 */

list copy_list(list l);
/*
 *Returns a copy of the given list.
 */

//DESTROY 

void destroy(list l);
/*
 * frees memory if its necessary
 */

#endif //