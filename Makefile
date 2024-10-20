# ***
# *** DO NOT modify this file 
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 

SRCS = main.c state_machine.c
OBJS = $(SRCS:%.c=%.o)

main: $(OBJS) 
	$(GCC) $(OBJS) -o main

.c.o: 
	$(GCC) -c $*.c 

test: main
	./main 264 > output
	diff output expected/expected

test_rand: main #Test your random number generation. Print rand()%100 15 times; if you get the same result, you are doing it correctly.
	./main 264 > output_rand
	diff output_rand expected/expected_rand

listen: main #run `make listen SEED=x`, where x is a number, to make different music
	./main $(SEED) > output
	python3 sound/compile_song.py

clean: # remove all machine generated files, backup files
	rm -f main *.o output output_rand
	rm -f song.wav
	rm -f *.bak *~


