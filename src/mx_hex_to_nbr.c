#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    if (!hex) return 0;
    unsigned long result = 0;
    while (*hex){
        char c = *hex++;
        int number;
        if (c >= '0' && c <= '9') number = c - '0';
        else if (c >= 'a' && c <= 'f') number = c - 'a' + 10;
        else if (c >= 'A' && c <= 'F') number = c - 'A' + 10;
        else return 0;
        result = (result << 4) | number;
    }
    return result;
}
