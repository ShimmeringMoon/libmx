#include "libmx.h"

char *mx_strnew(const int size) {
    if (size < 0) return NULL;
    char* result = malloc(size + 1 * sizeof(char));
    if (result == NULL) return NULL;
    mx_memset(result, '\0', size + 1);
    return result;
}
