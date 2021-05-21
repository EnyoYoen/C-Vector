#include "vector.h"

/*Vector create_vector()
{
    Vector vector;

    vector.data       = 0;
    vector.item_count = 0;
    vector.item_size  = 0;
    vector.size       = 0;
    
    return vector;
}
Vector create_vector_with_size(unsigned int size)
{
    void *data = malloc(size);
    if (data == 0)
    {
        exit(1);
    }

    Vector vector;

    vector.data       = data;
    vector.item_count = 0;
    vector.item_size  = 0;
    vector.size       = 0;

    return vector;
}*/
Vector create_vector(unsigned int item_size, unsigned int item_count)
{
    void *data = malloc(item_size * item_count);
    if (data == 0)
    {
        exit(1);
    }

    Vector vector;

    vector.data       = data;
    vector.item_count = 0;
    vector.item_size  = item_size;
    vector.size       = item_size * item_count;

    return vector;
}
void delete_vector(Vector vector)
{
    free(vector.data);
}

unsigned int vector_size(Vector *vector)
{
    return vector->size;
}
unsigned int vector_capacity(Vector *vector)
{
    unsigned int item_size = vector->item_size;
    if (item_size == 0)
    {
        return 0;
    }
    return vector->size / item_size;
}
unsigned char vector_is_empty(Vector *vector)
{
    if (vector->item_count == 0)
    {
        return 1;
    } else {
        return 0;
    }
}
void *vector_at(Vector *vector, unsigned int index)
{
    unsigned int item_size = vector->item_size;
    void *item = malloc(item_size);
    memcpy(item, vector->data + index * item_size, item_size);
    return item;
}
void vector_push(Vector *vector, void *item)
{
    void *data = vector->data;
    unsigned int oldSize = vector->size;
    unsigned int newSize = oldSize + vector->item_size;
    data = realloc(data, newSize);
    memcpy(data + oldSize, item, vector->item_size);
    vector->data = data;
    vector->size = newSize;
    vector->item_count++;
}
void vector_insert(Vector *vector, void *item, unsigned int index)
{
    void *data = vector->data;
    unsigned int item_size = vector->item_size;
    unsigned int newSize = vector->size + item_size;
    unsigned int offsetIndex = index * item_size;
    data = realloc(data, newSize);

    for (unsigned int i = newSize ; i > offsetIndex ; i -= item_size)
    {
        memcpy(data + i, data + i - item_size, item_size);
    }
    memcpy(data + offsetIndex, item, item_size);

    vector->data = data;
    vector->item_count++;
    vector->size = newSize;
}
void vector_prepend(Vector *vector, void *item)
{
    void *data = vector->data;
    unsigned int item_size = vector->item_size;
    unsigned int newSize = vector->size + item_size;
    data = realloc(data, newSize);

    for (unsigned int i = newSize ; i > 0 ; i -= item_size)
    {
        memcpy(data + i, data + i - item_size, item_size);
    }
    memcpy(data, item, item_size);

    vector->data = data;
    vector->item_count++;
    vector->size = newSize;
}
void vector_delete(Vector *vector, unsigned int index)
{
    void *data = vector->data;
    unsigned int item_size = vector->item_size;
    unsigned int oldSize = vector->size;
    unsigned int newSize = oldSize - item_size;

    for (unsigned int i = index * item_size ; i < oldSize ; i += item_size)
    {
        memcpy(data + i, data + i + item_size, item_size);
    }
    data = realloc(data, newSize);

    vector->data = data;
    vector->item_count--;
    vector->size = newSize;
}
void *vector_pop(Vector *vector)
{
    void *data = vector->data;
    unsigned int item_size = vector->item_size;
    unsigned int newSize = vector->size - item_size;
    void *popData = malloc(item_size);
    memcpy(popData, data + newSize, item_size);
    data = realloc(data, newSize);

    vector->data = data;
    vector->item_count--;
    vector->size = newSize;

    return popData;
}
void vector_remove(Vector *vector, void *item)
{
    void *data = vector->data;
    unsigned int size = vector->size;
    unsigned int item_size = vector->item_size;
    unsigned int counter = 0;
    for (unsigned int i = 0 ; i < size ; i += item_size)
    {
        if (memcmp(data + i, item, item_size))
        {
            counter++;
            for (unsigned int j = i ; j < size - item_size ; j += item_size)
            {
                memcpy(data + i, data + i + item_size, item_size);
            }
            size -= item_size;
        }
    }

    data = realloc(data, size);

    vector->data = data;
    vector->item_count -= counter;
    vector->size = size;
}
int vector_find(Vector *vector, void *item)
{
    void *data = vector->data;
    unsigned int item_size = vector->item_size;
    for (unsigned int i = 0 ; i < vector->size ; i += item_size)
    {
        if (memcmp(data + i, item, item_size))
        {
            return i / item_size;
        }
    }
    return -1;
}