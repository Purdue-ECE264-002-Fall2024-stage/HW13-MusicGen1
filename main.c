// ***
// *** DO NOT modify this file
// ***
#include <stdlib.h> 
#include <string.h> 
#include <stdio.h>
#include "fsm_macros.h"

// only 3 functions, no need to create .h file
void init_state(long seed);
void process_state(); 
void print_state();

int main(int argc, char * * argv)
{
  long seed = 264;
  if(argc>1) {
    seed = strtol(argv[1], NULL, 10);
  }
  printf("%i\n",HW13_SONG_SPEED); //Print bpm for python script
  init_state(seed); //Initialize FSM
  print_state(); //Print initialized state
  for(int i = 1;i < HW13_SONG_LENGTH; i++) {
    process_state();
    print_state();
  }
 
  return EXIT_SUCCESS;
}

