#include <string.h>
#include "array_list.h"

array_list_t *al_create(size_t data_size)
{
    array_list_t *array = malloc(sizeof(array_list_t));
    array->data_size = data_size;
    array->size = 0;
    array->capacity = INITIAL_CAP;

    array->data = malloc(sizeof(void *) * array->capacity);
    for (size_t i = 0; i < array->capacity; ++i) 
        array->data[i] = malloc(array->data_size);
    
    return array;
}

void _al_increase(array_list_t *array)
{
    size_t old_capacity = array->capacity;

    array->capacity = (size_t)(INC_FACTOR * array->capacity);
    array->data = realloc(array->data, sizeof(void *) * array->capacity);

    for (size_t i = old_capacity; i < array->capacity; ++i)
        array->data[i] = malloc(array->data_size);
}

void _al_decrease(array_list_t *array)
{
    for (size_t i = DEC_FACTOR * array->capacity; i < array->capacity; ++i)
        free(array->data[i]);

    array->capacity = (size_t)(DEC_FACTOR * array->capacity);
    array->data = realloc(array->data, array->capacity);
}

void al_push_back(array_list_t *array, void *data)
{
    al_push(array, data, array->size);
}

void al_push_front(array_list_t *array, void *data)
{
    al_push(array, data, 0);
}

void al_push(array_list_t *array, void *data, size_t pos)
{
    array->size++;
    if (array->size * INC_THRESHOLD >= array->capacity)
        _al_increase(array);

    for (size_t i = array->size; i > pos; --i)
        memcpy(array->data[i], array->data[i-1], array->data_size);
    memcpy(array->data[pos], data, array->data_size);
}

void al_remove_back(array_list_t *array)
{
    al_remove(array, array->size - 1);
}

void al_remove_front(array_list_t *array)
{
    al_remove(array, 0);
}

void al_remove(array_list_t *array, size_t pos)
{
    for (size_t i = pos; i < array->size - 1; ++i)
        memcpy(array->data[i], array->data[i+1], array->data_size);
    
    array->size--;
    if (array->capacity * DEC_THRESHOLD <= array->size && array->capacity * DEC_FACTOR > INITIAL_CAP)
        _al_decrease(array);  
}

void al_free(array_list_t *array, size_t pos)
{
    for (size_t i = 0; i < array->capacity; ++i)
        free(array->data[i]);
    free(array->data);
    free(array);
}