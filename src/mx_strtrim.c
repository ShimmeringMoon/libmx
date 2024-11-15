#include "libmx.h"

char *mx_strtrim(const char *str) {
    if (!str) return NULL;
    int len = mx_strlen(str);
    const char *start = str;
    const char *end = str + len -1;
    while (*start && mx_isspace(*start)) start++;
    // if the whole str is ws
    if (start > end) return mx_strnew(0);
    while (end > start && mx_isspace(*end)) end--;
    // create new str
    int n_len = (int)(end - start + 1);
    char *result = mx_strnew(n_len);
    if (!result) return NULL;
    return mx_strncpy(result, start, n_len);
}
