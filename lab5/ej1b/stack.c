#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 #include <stdbool.h>


struct _s_stack {
    stack_elem elem;
    stack next;
    unsigned int size;
};


stack stack_empty(){
    stack s = NULL;
    return s;
}


stack stack_push(stack s, stack_elem e){
    stack p = NULL;
    p = malloc(sizeof(struct _s_stack));
    p->elem = e;
    p->next = s;
    if(s!= NULL){
        p->size = s->size + 1;
    }else{
        p->size = 1;
    }
    s = p;
    return s;
}

//Operations

//Removes the top of the stack
stack stack_pop(stack s){
    assert(s != NULL);
    stack p = NULL;
    p = s;
    s = s->next;
    free(p);
    return s;
}

unsigned int stack_size(stack s){
    unsigned int sz = 0u;
    if(s != NULL){
        sz = s->size;
    }
    return sz;
}

//Returns the top element of the stack
stack_elem stack_top(stack s){
    assert(s != NULL);
    return s -> elem;
}

//Checks if the stack is empty
bool stack_is_empty(stack s){
    return s == NULL;
}

stack_elem *stack_to_array(stack s){
    unsigned int len = stack_size(s)-1u;
    stack q = NULL;
    stack_elem* array = NULL;
    q = s;
    array = calloc(stack_size(s), sizeof(stack_elem));
    while(!stack_is_empty(q)){
        array[len] = stack_top(q);
        q = q -> next;
        len--;
    }
    free(q);
    return array;
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

