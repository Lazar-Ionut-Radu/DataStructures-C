#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H


#define INC_THRESHOLD 0.8f   
#define DEC_THRESHOLD 0.5f
#define INC_FACTOR 2.0f
#define DEC_FACTOR 0.5f
#define INITIAL_CAP 10

#include <stdlib.h>

// Dinamically allocated array.
typedef struct array_list {
    size_t data_size;   // Size of the elements in bytes.
    size_t size;        // Number of elements.
    size_t capacity;    // Number of elements allocated in the array.
    void **data;        // The array.
} array_list_t;

// Creates an array with elements of data_size bytes.
// It allocates memory for INITIAL_CAP elements.
// @param data_size: The size in bytes of the elements
array_list_t *al_create(size_t data_size);

// Increases the capacity of the array by INC_FACTOR whenever 
// size / capacity exceeds INC_THRESHOLD.
void _al_increase(array_list_t *array);

// Decreases the capacity of the array by DEC_FACTOR whenever 
// size / capacity fells lower than DEC_THRESHOLD.
void _al_decrease(array_list_t *array);

// Adds an element at the end of the array.
// @param array: The array
// @param data: The new element
void al_push_back(array_list_t *array, void *data);

// Adds an element at the beginning of the array.
// @param array: The array
// @param data: The new element
void al_push_front(array_list_t *array, void *data);

// Adds an element at a specified position.
// @param array: The array
// @param data: The new element
// @param pos: The position where the element will be added
void al_push(array_list_t *array, void *data, size_t pos);

// Removes the last element.
// @param array: The array
void al_remove_back(array_list_t *array);

// Removes the first element.
// @param array: The array
void al_remove_front(array_list_t *array);

// Removes the the element at the position "pos".
// @param array: The array
// @param pos: The position of the removed element
void al_remove(array_list_t *array, size_t pos);

// Frees the memory of the array.
// @param array: The array
void al_free(array_list_t *array);

#endif // ARRAY_LIST_H
