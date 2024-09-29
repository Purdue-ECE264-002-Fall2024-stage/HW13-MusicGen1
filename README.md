# Music Generation via State Machine

Learning Goals 
==============

This assignment asks you to create a finite state machine and print its current state.

Background
=====

The goal of this assignment is to procedurally generate music using a state machine. It is very easy to convert random number generation into music. Each musical note can be described as a whole number of half-steps higher or lower than the middle C key, where a half-step is a transition from two keys on a piano directly next to each other. Each half-step represents a 5.946% increase in pitch, with an octave (12 half-steps) doubling pitch. As a result, we can play any note `n` half-steps above middle C by playing at the frequency `f`, where `f=f0*2^(n/12)`. If we were to generate a random number between -42 and 41 and plug it into the formula above, it would match the pitch of one of the keys on an 84-key piano.

However, random notes do not normally sound very good. To improve the quality of our music, we will use a very simple model which restricts which notes can follow the note last played. To do this, we will use a finite state machine.

A finite state machine is a method of programming in which the program keeps track of its current state. This can be useful when you have multiple asynchronous systems working with each other. FSMs are very common in embedded systems, and are particularly useful in hardware description languages such as VHDL. However, they can be useful anywhere. For this assignment, the state will be the note that was most recently played.

There are 12 notes in a standard octave. C, D, E, F, G, A and B are the "natural" notes, and they can be increase or decreased by a half step by adding a sharp (#) sign or flat (b) sign to the end. For this assignment, we will only be focusing on 5 natural notes: C, D, E, F, and G.

What You Need to Do
======================

Write the `init_state` function. This should seed the random number generator and
Write the `process_state` function. This should take the current state (note), generate a random number as described below, and then transition to the next note.
Finally, write the `print_state` function, which prints the properly formatted note.


The rules are:

1. Each note (C,D,E,F,G) should have its own unique state.
2. The initial state should should be that of the "C" note.
3. The transition from one note to another is random. The chances of a given transition are based on the table below.
4. Implement random number generation as described below; doing it differently may cause your otherwise working code to not work with the autograder.


When printing a note, you must also print 'n' (for natural). You should only put one note per line, or they will play simultaneously. To print a C note, you should print something like this:

```
printf("Cn\n");
```

If you want to listen to the music your program produces, there is a Python script that will play the song. You can use it by running `make listen` in the assignment directory.

Random Number Generation
==========

Since this assignment uses pseudorandom number generation, in order to ensure consistency between tests, you will need to use a constant seed. This can be found in the file `fsm_macros.h`. When testing against the expected output, you should set `HW13_RAND_SEED` to `264`, which is its default value. You can change this to produce different music.

Random numbers should be generated using the standard `rand` function. This will generate a very large random number. Generate a random number, modulate by 100, and use that to evaluate the state transition, moving from left to right in the table.

For example: Note X transitions as follows.
Note|C  |D  |E  |F  |G
X   |20%|10%|5% |35%|30%

If rand()%100 is between 0 and 19, the next note is C.
If rand()%100 is between 20 and 29, the next note is D.
If rand()%100 is between 30 and 34, the next note is E.
If rand()%100 is between 35 and 69, the next note is F.
If rand()%100 is between 70 and 99, the next note is G.

**Only generate the random number one time per `process_state`.** Generating it more than once per function call will make it generate different numbers.

You can test your random number generation by running `make test_rand`. With the default seed, print out your random number every time you call it, and don't print anything else. If you see nothing in the diff, then you are producing the correct random numbers.

Submission
==========

```
zip hw13.zip state_machine.c
```

Upload hw13.zip to Gradescope

Additional Reading
==================

