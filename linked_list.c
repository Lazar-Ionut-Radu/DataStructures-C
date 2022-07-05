#include "linked_list.h"
#include <stdio.h>
#include <string.h>

linked_list_t *ll_create(size_t data_size)
{
    linked_list_t *list;
    list = malloc(sizeof(linked_list_t));

    list->data_size = data_size;
    list->size = 0;

    list->head = malloc(sizeof(list_node_t));
    list->head = NULL;

    return list;
}

void ll_push_back(linked_list_t *list, void *data)
{
    if (!list)
        return;

    list_node_t *new_node;
    new_node = malloc(sizeof(list_node_t));

    new_node->data = malloc(list->data_size);
    memcpy(new_node->data, data, list->data_size);

    if (!list->size) {
        list->head = new_node;
        list->head->next = list->head;
        list->head->prev = list->head;
    }
    else {
        new_node->next = list->head;
        new_node->prev = list->head->prev;
        list->head->prev->next = new_node;
        list->head->prev = new_node;
    }

    list->size++;
}

void ll_push_front(linked_list_t *list, void *data) 
{
    if (!list)
        return;

    list_node_t *new_node;
    new_node = malloc (sizeof(list_node_t));

    new_node->data = malloc(list->data_size);
    memcpy(new_node->data, data, list->data_size);
    
    if (!list->size) {
        list->head = new_node;
        list->head->next = list->head;
        list->head->prev = list->head;
    }
    else {
        new_node->next = list->head;
        new_node->prev = list->head->prev;
        list->head->prev->next = new_node;
        list->head->prev = new_node;
        list->head = new_node;
    }

    list->size++;
}

void ll_push(linked_list_t *list, void *data, size_t pos)
{
    if (!list)
        return;

    if (list->size < pos)
        return;

    if (list->size == 0)
        return ll_push_front(list, data);

    list_node_t *node = list->head;
    for (size_t i = 1; i <= pos; ++i)
        node = node->next;

    list_node_t *new_node;
    new_node = malloc(sizeof(list_node_t));
    new_node->data = malloc(list->data_size);
    memcpy(new_node->data, data, list->data_size);

    new_node->next = node;
    new_node->prev = node->prev;
    node->prev->next = new_node;       
    node->prev = new_node;

    if (pos == 0) {
        list->head = new_node;
    }

    list->size++;
}

list_node_t *ll_remove_back(linked_list_t *list)
{
    if (!list)
        return NULL;
    
    if (!list->size)
        return NULL;

    list_node_t *removed_node = list->head->prev;
    free(removed_node->data);

    if (list->size == 1) {
        list->head = NULL;
        list->size = 0;
        return removed_node;
    }
    else {
        removed_node->next->prev = removed_node->prev;
        removed_node->prev->next = removed_node->next;
        
        list->size--;
        return removed_node;
    }   
}

list_node_t *ll_remove_front(linked_list_t *list)
{
    if (!list)
        return NULL;
    
    if (!list->size)
        return NULL;


    list_node_t *removed_node = list->head;
    free(removed_node->data);

    if (list->size == 1) {
        list->head = NULL;
        list->size = 0;
        return removed_node;
    }
    else {
        list->head = list->head->next;

        removed_node->next->prev = removed_node->prev;
        removed_node->prev->next = removed_node->next;
        
        list->size--;
        return removed_node;
    }
}

list_node_t *ll_remove(linked_list_t *list, size_t pos)
{
    if (!list)
        return NULL;

    if (list->size == 0)
        return NULL;

    if (pos > list->size)
        return NULL;
    
    if (pos == 0) 
        return ll_remove_front(list);

    list->size--;

    list_node_t *removed_node = list->head;
    for (size_t i = 1; i <= pos; ++i)
        removed_node = removed_node->next;

    removed_node->next->prev = removed_node->prev;
    removed_node->prev->next = removed_node->next;

    return removed_node;
}

void *ll_free(linked_list_t *list)
{
    while (list->size) {
        free(ll_remove_back(list));
    }

    free(list);
    list = NULL;
}

