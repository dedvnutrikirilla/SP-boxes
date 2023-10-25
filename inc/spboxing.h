#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#define B(x) binary_string_to_int(#x)

// S-Box parts
uint8_t substitute(uint8_t bit8);
uint8_t de_substitute(uint8_t s_bit8);
//
// P-Box parts
uint8_t permutate(uint8_t bit8);
uint8_t de_permutate(uint8_t p_bit8);
//
// Utils
uint8_t binary_string_to_int(char *s);
char *binary_int_to_string(uint8_t num, char *s);
void binary_out(uint8_t num);
uint8_t find_index(uint8_t n, uint8_t len, const uint8_t *arr);
//
uint8_t cipher(uint8_t num);
uint8_t decipher(uint8_t num);
