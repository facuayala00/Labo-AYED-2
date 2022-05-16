#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"
#include <stdbool.h>


struct _Node{
    list_elem elem;
    struct _Node *next;
};

list empty_list(void){
    list l = NULL;
    return l;
}

list addl(list l, list_elem e){
    list p = NULL;
    p = malloc(sizeof(list));
    p->elem = e;
    p->next = l;
    l = p;
    return l;
}

//OPERATIONS
bool is_empty(list l){
    bool b = l == NULL;
    return b;
}

list_elem head(list l){
    assert(!is_empty(l));
    list_elem e = l->elem;
    return e;
}


list tail(list l){
    assert(!is_empty(l));
    list p = NULL;
    p = malloc(sizeof(list));
    p = l;
    l = l -> next;
    free(p);
    return l;
}


list addr(list l, list_elem e){
    list p, q;
    p = NULL;
    q = NULL;
    q = malloc(sizeof(list));
    q -> elem = e;
    q -> next = NULL;
    if(!(is_empty(l))){
        p = l;
        while(p -> next != NULL){
            p = p -> next;
        }
        p -> next = q;
    }
    else{
        l = q;
    }
    return l;
}

unsigned int length(list l){
    unsigned int i = 0;
    list p = NULL;
    p = l;
    while (p != NULL){
        i++;
        p = p -> next;
    }
    return i;
}

list_elem index(list l, unsigned int n){
    assert(length(l)>n);
    unsigned int i = 0;
    list_elem e;
    list p = NULL;
    while (i < n && !(is_empty(l))){
        p = l;
        l = p -> next;
        e = p -> elem;
        i++;
    }
    return e;
}


list take(list l, unsigned int n){
    assert(length(l) > n);
    list p, q;
    p = NULL;
    q = NULL;
    p = l;
    for(unsigned int i = 0; i < n-1; i++){
        if (p != NULL){
            q = p->next;
        }
    }
    if(p != NULL){
        q = p->next;
        p ->next = NULL;
        while(q != NULL){
            p = q;
            q = q->next;
            free(p);
        }
    }
    return l;
}


list drop(list l, unsigned int n){
    list p = NULL;
    unsigned int i = 0;
    while(i < n && l!=NULL){
        p = l;
        l = p->next;
        free(p);
        i++;
    }
    return l;
}

list copy_list(list l){
    list p, q, l2;
    l2 = NULL;
    p = NULL;
    q = NULL;
    l2 = empty_list();
    p = l;
    if(p != NULL){
        l2 = malloc(sizeof(list));
        l2 -> elem = l -> elem;
        q = l2;
        while(p->next != NULL){
            q->next = malloc(sizeof(list));
            q = q->next;
            p = p->next;
            q->elem = p->elem;
        }
        q->next = NULL;
    }else{
        l2 = NULL;
    }
    return l2;
}

list concat(list l, list l2){
    list p, l2_copy;
    p = NULL;
    l2_copy = NULL;
    l2_copy = copy_list(l2);
    if(l == NULL){
        l = l2_copy;
    }else{
        p = l;
        while (p -> next != NULL){
            p = p -> next;
        }
        p -> next = l2_copy;
    }
    return l;
}



//DESTROY 

void destroy(list l){
    list p = NULL;
    while(l != NULL){
        p = l;
        l = p->next;
        free(p);
    }
}
