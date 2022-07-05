#ifndef QUEUE_H
#define QUEUE_H

#include "linked_list.h"

typedef struct queue {
    linked_list_t *q;
} queue_t;

queue_t *q_create(size_t data_size);

void q_push(queue_t *queue, void *data);

void q_pop(queue_t *queue);

void *q_peek(queue_t *queue);

void q_free(queue_t *queue);

#endif // QUEUE_H
