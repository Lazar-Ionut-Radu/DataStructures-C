#include "queue.h"
#include "string.h"

queue_t *q_create(size_t data_size)
{
    queue_t *queue = malloc(sizeof(queue_t));
    queue->q = ll_create(data_size); 

    return queue;
}

void q_push(queue_t *queue, void *data)
{
    ll_push_front(queue->q, data);
}

void q_pop(queue_t *queue)
{
    free(ll_remove_back(queue->q));
}

void *q_peek(queue_t *queue)
{
    void *data = malloc(queue->q->data_size);
    memcpy(data, queue->q->head->prev->data, queue->q->data_size);

    return data;
}

void q_free(queue_t *queue)
{
    ll_free(queue->q);
    
    free(queue);
    queue = NULL;
}

