# SP-boxes
A simple implementation of a Substitution-Permutation Box (SP-Box) cipher in C. The cipher operates on 8-bit data blocks, applying substitution and permutation transformations.

## Build
To build the project run makefile in the root directory. It compiles source code using gcc with c11 standart (sorry its not c17) into an executable.
```bash
make
```
There may appear errors due to the usage of `0b0000` int format in sp-boxes. They should be commented by default. Comment them back, they are used only for better example of how bits from substitution/permutation tables look like.

## Use
Find the example of usage in `test.c` file in `src/` directory.

`s_box.c` and `p_box.`c contain both the respective tables and the algorithms for them. There are no reverse tables, only reverse functions to course through normal tables. In `cipher.c` you may find (or may not find))0))0)))) the ciphering algorithm and the key. Key is split into 8-bit blocks that are XORed with inbetween result of S-box and P-box.
In case you want to test only s/p boxes, set `KEY = 0` and `ROUNDS = 1`
