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

array_list_t *al_create(size_t data_size);

void _al_increase(array_list_t *array);

void _al_decrease(array_list_t *array);

void al_push_back(array_list_t *array, void *data);

void al_push_front(array_list_t *array, void *data);

void al_push(array_list_t *array, void *data, size_t pos);

void al_remove_back(array_list_t *array);

void al_remove_front(array_list_t *array);

void al_remove(array_list_t *array, size_t pos);

void al_free(array_list_t *array, size_t pos);

#endif // ARRAY_LIST_H
