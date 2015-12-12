/* My personal library */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "mylib.h"

#define RANDBUFFER 1000

static clock_t start, stop;    //For Tick and Tock time measurement functions

int *GenerateRandomArray(int array[], int arrayLength, int min, int max)
{
  int i;
  int range = max - min;

  for (i = 0; i < arrayLength; i++)
    {
      int newNumber = min + (RandInt() % range);
      array[i] = newNumber;
    }
  return array;
}

// Create a buffer and asks you to type something into it. 
void EnterSomething(char *buffer, int buffSize)
{
  //Allocate the buffer for the input:
  printf("Enter something: ");
  if(fgets(buffer, buffSize, stdin) == NULL)
    {
      printf("\n Buffer limit of %d exceeded in function EnterSomething", buffSize);
    }
  printf("\nYou entered %s", buffer);
}

//Returns the index of the value of the searched flag eg -c, or -1 if not found
int IfCommandLineContains(char searched[], char *input[], int inputLength)
{
  int result = -1;

  int i;
  for(i = 0; i < inputLength; i++)
    {
      if(!strcmp(input[i], searched))
	{
	  result = i + 1;
	}
    }
  return result;
}

// Determines if an int is a power of 2
int IsPowerOfTwo(int input)
{
  int result;
  int remainder = 0;
  while(!remainder && input > 2)
    {
      remainder = input % 2;
      input /= 2;
    }

  if(remainder == 1)
    {
      result = 0;
    }
  else
    {
      result = 1;
    }

  return result;
}

// My implementation of generating a random integer between 0 and RAND_MAX
int RandInt()
{
  static int randBuffIndex = 0;
  static int randoms[RANDBUFFER];
  int result;

  int condition = (randBuffIndex < RANDBUFFER) && ((int)randBuffIndex != 0);
  if(condition)
    {
      result = randoms[randBuffIndex++];
    }
  else
    {
      srand(time(0));
      int i; 
      for(i = 0; i < RANDBUFFER; i++)
	{
	  randoms[i] = rand();
	}
      randBuffIndex = 1;
      result = RandInt();
    }

  return result;
}

// Tock will return time elapsed from the time this function is called
void Tick()
{
  start = clock();
}

// Elapsed time in milliseconds since Tick
int Tock()
{
  stop = clock();
  int computeTime = 1000 * (stop - start) / CLOCKS_PER_SEC;
  return computeTime;
}

