#ifndef _MYLIB_H_
#define _MYLIB_H_

void EnterSomething(char *buffer, int buffSize);
int IfCommandLineContains(char searched[], char *input[], int inputLength); 
int IsPowerOfTwo(int input);
int RandInt();
void Tick();
int Tock();
#endif
