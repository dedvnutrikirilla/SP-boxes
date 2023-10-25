#include"../inc/spboxing.h"

int main() {
    uint8_t a = 0b10010100;

    binary_out(a);
    
    printf("\nciphering:\t");
    uint8_t b = cipher(a);
    binary_out(b);

    printf("\ndeciphering:\t");
    uint8_t c = decipher(b);
    binary_out(c);

    return 0;
}