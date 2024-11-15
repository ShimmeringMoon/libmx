#include "libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (buf_size == 0 || fd < 0)
        return -2;

    *lineptr = (char *)mx_realloc(*lineptr, buf_size);
    if (*lineptr == NULL)
        return -1;

    size_t current_size = malloc_usable_size(*lineptr);
    mx_memset(*lineptr, '\0', current_size);

    size_t bytes = 0;
    char buf;
    
    if (read(fd, &buf, 1) <= 0)
        return -1;

    if (buf == delim)
        return bytes;

    (*lineptr)[bytes++] = buf;

    while (read(fd, &buf, 1) > 0) {
        if (buf == delim)
            break;

        if (bytes >= current_size - 1) {
            *lineptr = (char *)mx_realloc(*lineptr, bytes + 2);
            if (*lineptr == NULL)
                return -1;
            current_size = malloc_usable_size(*lineptr);
        }

        (*lineptr)[bytes++] = buf;
    }

    (*lineptr)[bytes] = '\0'; 

    return (int)bytes;
}
