#include"../inc/spboxing.h"

// Used for better understanding of bit operations, better be deleted
/*const uint8_t s_box2[16] = {
    0b1110,
    0b0100,
    0b1101,
    0b0001,
    0b0010,
    0b1111,
    0b1011,
    0b1000,
    0b0011,
    0b1010,
    0b0110,
    0b1100,
    0b0101,
    0b1001,
    0b0000,
    0b0111,
};*/

const uint8_t s_box[16] = { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7 };

uint8_t substitute(uint8_t bit8) {
    uint8_t s_bit8, bit4_a, bit4_b;

    bit4_a = s_box[bit8 >> 4];
    bit8 <<= 4;
    bit4_b = s_box[bit8 >> 4];

    s_bit8 = (bit4_a << 4)|bit4_b;

    return s_bit8;
};

uint8_t de_substitute(uint8_t s_bit8) {
    uint8_t bit8, bit4_a, bit4_b;

    bit4_a = find_index(s_bit8 >> 4, 16, s_box);
    s_bit8 <<= 4;
    bit4_b = find_index(s_bit8 >> 4, 16, s_box);

    bit8 = (bit4_a << 4)|bit4_b;
    return bit8;
};
