// ***
// *** DO NOT modify this file
// ***
#include <stdlib.h> 
#include <string.h> 
#include <stdio.h>
#include "fsm_macros.h"

// only 3 functions, no need to create .h file
void init_state();
void process_state(); 
void print_state();

int main()
{

  printf("%i\n",HW13_SONG_SPEED); //Print bpm for python script
  init_state(); //Initialize FSM
  print_state(); //Print initialized state
  for(int i = 1;i < HW13_SONG_LENGTH; i++) {
    process_state();
    print_state();
  }
 
  return EXIT_SUCCESS;
}

