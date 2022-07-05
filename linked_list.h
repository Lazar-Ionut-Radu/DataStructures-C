#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdlib.h>

typedef struct list_node {
    void *data;             
    struct list_node *next;        
    struct list_node *prev;        
} list_node_t;

typedef struct linked_list{
    size_t data_size;
    size_t size;
    list_node_t *head;
} linked_list_t;

linked_list_t *ll_create(size_t data_size);

void ll_push_back(linked_list_t *list, void *data);

void ll_push_front(linked_list_t *list, void *data);

void ll_push(linked_list_t *list, void *data, size_t pos);

list_node_t *ll_remove_back(linked_list_t *list);

list_node_t *ll_remove_front(linked_list_t *list);

list_node_t *ll_remove(linked_list_t *list, size_t pos);

void *ll_free(linked_list_t *list);

#endif // LINKED_LIST_H
