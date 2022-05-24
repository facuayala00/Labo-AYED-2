#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 #include <stdbool.h>

struct _Node{
    stack_elem elem;
    struct _Node *next;
};

stack stack_empty(){
    stack s = NULL;
    return s;
}


stack stack_push(stack s, stack_elem e){
    stack p = NULL, q = NULL;
    p = malloc(sizeof(stack));
    q = s;
    p->elem = e;
    p->next = NULL;
    if(s == NULL){
        s = p;
    }
    else{
        while(q->next != NULL){
            q = q->next;
        }
        q->next = p;
    }
    return s;
}

//Operations

//Removes the top of the stack
stack stack_pop(stack s){
    assert(s != NULL);
    stack p = NULL, q = NULL;
    p = malloc(sizeof(stack));
    q = s;
    while(q->next != NULL){
        q = q->next;
    }
    p = q;
    free(p);
    return s;
}

unsigned int stack_size(stack s){
    unsigned int i = 0;
    stack q = NULL;
    q = s;
    while (q != NULL){
        i++;
        q = q -> next;
    }
    return i;
}

//Returns the top element of the stack
stack_elem stack_top(stack s){
    assert(s != NULL);
    stack_elem e; 
    stack q = NULL;
    q = s;
    while(q->next != NULL){
        q = q->next;
    }
    e = q -> elem;
    return e;
}

//Checks if the stack is empty
bool stack_is_empty(stack s){
    return s == NULL;
}

stack_elem *stack_to_array(stack s){
    
}

//Destroys the stack
stack stack_destroy(stack s){
    stack q = NULL;
    q = s;
    while(s != NULL){
        q = s;
        s = s -> next;
        free(q);
    }
    return s;
}