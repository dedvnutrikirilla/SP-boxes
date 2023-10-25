#include"../inc/spboxing.h"

// Used for better understanding of bit operations, better be deleted
/*const uint8_t p_box2[8] = {
    0b00100000,
    0b00010000,
    0b10000000,
    0b00000100,
    0b01000000,
    0b00001000,
    0b00000001,
    0b00000010,
};*/

const uint8_t p_box[8] = {5, 4, 7, 2, 6, 3, 0, 1};

uint8_t permutate(uint8_t bit8) {
    uint8_t p_bit8 = 0;

    for (int i = 0; i <= 7; i++) {
        uint8_t num = bit8 >> i;
        p_bit8 |= (num & 1) << p_box[i];
    }

    return p_bit8;
}

uint8_t de_permutate(uint8_t p_bit8) {
    uint8_t bit8 = 0;

    for (int i = 0; i < 8; i++) {
        uint8_t num = p_bit8 >> i;
        bit8 |= (num & 1) << find_index(i, 8, p_box);
    }

    return bit8;
}
