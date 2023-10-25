all: # add -Wpedantic if you remove all `0b` int declarations, they are extension of gcc
	gcc -std=c11 -Wall -Werror -Wextra -ggdb3 -I ./inc/ -s ./src/*.c -o main 
