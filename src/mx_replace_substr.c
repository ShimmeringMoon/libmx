#include "libmx.h"

static char *logic(const char *str, const char *sub, const char *replace) {
    int sub_len = mx_strlen(sub);
    int rep_len = mx_strlen(replace);
    int sub_amount = mx_count_substr(str, sub);

    if (sub_amount == 0) return mx_strdup(str);

    int len = mx_strlen(str) + sub_amount * (rep_len - sub_len);
    char *result = mx_strnew(len);
    if (result == NULL) return NULL;
    char *r_ptr = result;
    const char *s_ptr = str;
    const char *temp;

    while ((temp = mx_strstr(s_ptr, sub)) != NULL) {
        r_ptr = mx_strncpy(r_ptr, s_ptr, (int)(temp - s_ptr));
        r_ptr += temp - s_ptr;
        r_ptr = mx_strncpy(r_ptr, replace, rep_len);
        r_ptr += rep_len;
        s_ptr = temp + sub_len;
    }

    mx_strcpy(r_ptr, s_ptr);
    return result;
}

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (str == NULL || sub == NULL || replace == NULL) return NULL;
    if (mx_strlen(str) == 0 || mx_strlen(sub) == 0) return mx_strdup(str);
    return logic(str, sub, replace);
}
