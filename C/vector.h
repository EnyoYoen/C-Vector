#include <stdlib.h>
#include <string.h>

typedef struct {
    void* data;
    unsigned int size;
    unsigned int item_size;
    unsigned int item_count;
} Vector;

/*Vector create_vector();
Vector create_vector_with_size(unsigned int size);*/
Vector create_vector(unsigned int item_size, unsigned int items_count);
void delete_vector(Vector vector);

unsigned int  vector_size       (Vector *vector);
unsigned int  vector_capacity   (Vector *vector);
unsigned char vector_is_empty   (Vector *vector);
void *        vector_at         (Vector *vector, unsigned int index);
void          vector_push       (Vector *vector, void *item);
void          vector_insert     (Vector *vector, void *item, unsigned int index);
void          vector_prepend    (Vector *vector, void *item);
void          vector_delete     (Vector *vector, unsigned int index);
void *        vector_pop        (Vector *vector);
void          vector_remove     (Vector *vector, void *item);
int           vector_find       (Vector *vector, void *item);