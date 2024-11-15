#include "libmx.h"

void *mx_realloc(void *ptr, size_t new_size) {
    size_t cur_size;
    void *new_ptr;

    if (ptr == NULL) {
        return malloc(new_size);
    }

    cur_size = malloc_usable_size(ptr);
    if (new_size <= cur_size) {
        return ptr;
    }

    new_ptr = malloc(new_size);
    if (new_ptr == NULL) {
        return NULL; 
    }

    mx_memcpy(new_ptr, ptr, cur_size);
    free(ptr);
    return new_ptr;
}
