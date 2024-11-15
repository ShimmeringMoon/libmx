#include "libmx.h"

static char *get_word(const char *s, char c) {
    while (*s == c && *s) s++;
    int ind = mx_get_char_index(s, c);
    if (ind == -1) ind = mx_strlen(s);
    char *result = mx_strnew(ind);
    if (result == NULL) return NULL;
    mx_strncpy(result, s, ind);
    return result;
}

static void *free_memory(char **arr, int count) {
    if (arr == NULL) return NULL;
    for (int j = 0; j < count; j++) free(arr[j]);
    free(arr);
    return NULL;
}

char **mx_strsplit(const char *s, char c) {
    if (s == NULL) return NULL;
    int word_cnt = mx_count_words(s, c);
    if (word_cnt == 0) {
        char **arr = malloc(sizeof(char *));
        if (arr != NULL) arr[0] = NULL;
        return arr;
    }
    char **arr = malloc((word_cnt + 1) * sizeof(char *));
    if (arr == NULL) return NULL;
    for (int i = 0; i < word_cnt; ++i) {
        char *word = get_word(s, c);
        if (word == NULL) return free_memory(arr, i);
        arr[i] = word;
        while (*s == c && *s) s++;
        s += mx_strlen(word);
    }
    arr[word_cnt] = NULL;
    return arr;
}
