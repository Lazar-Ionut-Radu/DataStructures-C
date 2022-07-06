#ifndef QUEUE_H
#define QUEUE_H

#include "linked_list.h"

typedef struct queue {
    linked_list_t *q;
} queue_t;

// Creates a queue.
// @param data_size: The size in bytes of the elements of the queue.
queue_t *q_create(size_t data_size);

// Adds an element in the queue.
// @param queue: The queue
// @param data: The added element
void q_push(queue_t *queue, void *data);

// Removes an element from the queue.
// @param queue: The queue
void q_pop(queue_t *queue);

// Returns the element at the top of the queue
// @param queue: The queue
void *q_peek(queue_t *queue);

// Frees the memory of the queue.
// @param queue: The queue
void q_free(queue_t *queue);

#endif // QUEUE_H
