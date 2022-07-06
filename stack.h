#ifndef STACK_H
#define STACK_H

#include "linked_list.h"

typedef struct stack {
    linked_list_t *s;
} stack_t;

// Creates a stack.
// @param data_size: The size in bytes of the elements of the stack
stack_t *st_create(size_t data_size);

// Returns the element at the top of the stack.
// @param stack: The stack
void *st_peek(stack_t *stack);

// Adds an element in the stack.
// @param stack: The stack
// @param data: The added element
void st_push(stack_t *stack, void *data);

// Removes an element from the stack
// @param stack: The stack.
void st_pop(stack_t *stack);

// Frees the memory of the stack
// @param stack: The stack
void st_free(stack_t *stack);

#endif // STACK_H
