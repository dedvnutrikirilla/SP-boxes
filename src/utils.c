#include"../inc/spboxing.h"

uint8_t binary_string_to_int(char *s) {
    uint8_t i = 0;
    while(*s) {
        i <<= 1;
        i += *s++ - '0';
    }
    return i;
}

void binary_out(uint8_t num) {
    putchar('0');
    putchar('b');
    for (int i = 7; i >= 0; i--) {
        putchar(((num >> i) & 1) ? '1' : '0');
    }
    return;
}

char *binary_int_to_string(uint8_t num, char *s) {
    /*ya better set size to 11*/
    if (!s){
        perror("binary_int_to_string: String is NULL");
        s = "no string?";
        return s;
    }

    s[0] = '0';
    s[1] = 'b';
    for (int i = 2; i <= 9; i++) {
        s[i] = ((num >> (9 - i)) & 1) ? '1' : '0';
    }
    s[10] = '\0';
    return s;
}

uint8_t find_index(uint8_t n, uint8_t len, const uint8_t *arr) {
    for (uint8_t i = 0; i < len; i++) {
        if (arr[i] == n)
            return i;
    }

    perror("Match not found! returning 0");
    return 0;
}