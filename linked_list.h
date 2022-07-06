#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdlib.h>

// The node of a circular doubly linked list.
typedef struct list_node {
    void *data;           
    struct list_node *next; 
    struct list_node *prev;        
} list_node_t;

// A circular doubly linked list.
typedef struct linked_list{
    size_t data_size;       // The size in bytes of the data in the nodes.
    size_t size;            // The number of nodes in the list.
    list_node_t *head;      
} linked_list_t;

// Creates a new list.
// @param: data_size: The size in bytes of the data in the nodes.
linked_list_t *ll_create(size_t data_size);

// Adds a new node at the end of the list.
// @param list: The list
// @param data: The data inside the newly inserted node 
void ll_push_back(linked_list_t *list, void *data);

// Adds a new node at the beginning of the list (making it the new head of the list).
// @param list: The list
// @param data: The data inside the newly inserted node
void ll_push_front(linked_list_t *list, void *data);

// Adds a new node at the position "pos" in the list.
// @param list: The list
// @param data: The data inside the newly inserted node
// @param pos: The position where the node will be inserted
void ll_push(linked_list_t *list, void *data, size_t pos);

// Removes the last node.
// @param list: The list
list_node_t *ll_remove_back(linked_list_t *list);

// Removes the first node.
// @param list: The list
list_node_t *ll_remove_front(linked_list_t *list);

// Removes the node ar position "pos" in the list.
// @param list: The list
// @param pos: The position of the removed node
list_node_t *ll_remove(linked_list_t *list, size_t pos);

// Frees the memory of the list.
// @param list: The list.
void *ll_free(linked_list_t *list);

#endif // LINKED_LIST_H
