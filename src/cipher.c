#include"../inc/spboxing.h"

const int ROUNDS = 10;
const unsigned int KEY = 26141796;
int SIZE = 0;

uint8_t *key_cutter() {
    int temp_key = KEY, size = 0;
    while (temp_key > 0) {
        temp_key >>= 8;
        size++;
    }
    SIZE = size;
    temp_key = KEY;// reset temple key back

    uint8_t *keyarr = (uint8_t *)malloc(size * sizeof(uint8_t)); //sizeof uint8_t is kinda obviously 8?
    if (!keyarr)
        return NULL;
    for(int i = size; i >= 0; i--){
        keyarr[i] = temp_key & 255; // 255 = 0b11111111
        temp_key >>= 8;
    }

    return keyarr;
}

uint8_t cipher(uint8_t num) {
    uint8_t *keyarr = key_cutter();
    short key_index = 0;
    for (int i = 0; i < ROUNDS; i++) {
        uint8_t temp = substitute(num);

        temp ^= keyarr[key_index];
        key_index++;
        if(key_index >= SIZE)
            key_index = 0;
        
        num = permutate(temp);
    }
    free(keyarr);
    printf("\n");
    return num;
}

uint8_t decipher(uint8_t num) {
    uint8_t *keyarr = key_cutter();
    short key_index = (ROUNDS % SIZE) - 1;
    for (int i = 0; i < ROUNDS; i++) {
        uint8_t temp = de_permutate(num);

        temp ^= keyarr[key_index];
        key_index--;
        if(key_index < 0)
            key_index = SIZE - 1;

        num = de_substitute(temp);
    }
    free(keyarr);
    printf("\n");
    return num;
}
