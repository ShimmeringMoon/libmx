#include "libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    if (lst == NULL || lst->next == NULL || cmp == NULL) return lst;
    bool sorted = false;
    t_list *temp;
    while (!sorted) {
        sorted = true;
        temp = lst;
        while (temp->next != NULL) {
            if (cmp(temp->data, temp->next->data)) {
                mx_swap_list_node(temp, temp->next);
                sorted = false;
            }
            temp = temp->next;
        }
    }
    return lst;
}
