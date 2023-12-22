#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define DEAD 46
#define ALIVE 42

char* allocateArray(int __size);
char** allocateMatrix(int __size);
char** copyMatrix(char** matrix, int __size);

void print(char** matrix, int __size);
char** evolve(char** matrix, int __size);

int calculateNeighbours(char** matrix, int i, int j, int __size);
void readInitialState(char** matrix, int __size);

void freeMemory(char** matrix, int __size);
void bufferFlush();
int generateRandomNumber();

#endif
