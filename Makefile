all: # add -Wpedantic
	gcc -std=c11 -Wall -Werror -Wextra -ggdb3 -I ./inc/ -s ./src/*.c -o main 
