#include <stdio.h>
#include "vector.h"

void main(void)
{
    /*Vector vector = create_vector();
    vector = create_vector_with_size(20);*/
    Vector vector = create_vector(4, 10);

    printf("%u\n", vector_size(&vector));
    printf("%u\n", vector_capacity(&vector));
    printf("%u\n\n", vector_is_empty(&vector));

    int a = 64;
    vector_push(&vector, &a);
    
    printf("%u\n", vector_size(&vector));
    printf("%u\n", vector_capacity(&vector));
    printf("%u\n\n", vector_is_empty(&vector));

    int b = 65;
    vector_insert(&vector, &b, 0);
    
    printf("%u\n", vector_size(&vector));
    printf("%u\n\n", vector_capacity(&vector));

    int *aa = (int *)vector_at(&vector, 1);
    int *bb = (int *)vector_at(&vector, 0);

    printf("%i\n", *aa);
    printf("%i\n\n", *bb);


    delete_vector(vector);
}