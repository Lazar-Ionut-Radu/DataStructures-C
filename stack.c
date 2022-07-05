#include "stack.h"
#include <string.h>

stack_t *st_create(size_t data_size)
{
    stack_t *stack = malloc(sizeof(stack_t));
    stack->s = ll_create(data_size);

    return stack;
}

void *st_peek(stack_t *stack)
{
    void *data = malloc(stack->s->data_size);
    memcpy(data, stack->s->head->prev->data, stack->s->data_size);

    return data;
}

void st_push(stack_t *stack, void *data)
{
    ll_push_back(stack->s, data);
}

void st_pop(stack_t *stack)
{
    free(ll_remove_back(stack->s));
}

void st_free(stack_t *stack)
{
    ll_free(stack->s);
    
    free(stack);
    stack = NULL;
}
