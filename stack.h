#ifndef STACK_H
#define STACK_H

#include "linked_list.h"

typedef struct stack {
    linked_list_t *s;
} stack_t;

stack_t *st_create(size_t data_size);

void *st_peek(stack_t *stack);

void st_push(stack_t *stack, void *data);

void st_pop(stack_t *stack);

void st_free(stack_t *stack);

#endif // STACK_H
