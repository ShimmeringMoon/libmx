#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    unsigned char *where = (unsigned char *)big;
    unsigned char *what = (unsigned char *)little;

    if (big_len >= little_len && big_len > 0 && little_len > 0) {
        for (size_t i = 0; i <= big_len - little_len; i++) {
            if (mx_memcmp(where + i, what, little_len) == 0) {
                return where + i;
            }
        }
    }
    return NULL;
}
