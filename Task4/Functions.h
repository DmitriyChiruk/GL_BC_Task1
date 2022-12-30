#pragma once
#include <stdio.h>
#include <stdlib.h>

// Codes that state for different elements of the labirinth.
#define WALL 1
#define ENTRYCODE 7
#define FINISHCODE 8
#define EMPTYCELL 0

// Dimentions of the labirinth.
#define LABHEIGHT 5
#define LABWIDTH 5

// Print the labyrinth to the console.
void ShowLabyrinth(unsigned int labyrinth[LABHEIGHT][LABWIDTH]);

// Set position to the ENTRYPOINT location and return 0 if it`s absent.
int FindStart(unsigned int labyrinth[LABHEIGHT][LABWIDTH], unsigned int position[2]);

// Check if the labirinth have finish.
int HasFinish(unsigned int labyrinth[LABHEIGHT][LABWIDTH]);

// Change direction of the movement by rotating to left.
void RotateLeft(int direction[2]);

// Change direction of the movement by rotating to right.
void RotateRight(int direction[2]);

// Main logick of movement inside the labyrinth.
void Move(unsigned int labyrinth[LABHEIGHT][LABWIDTH], unsigned int position[2], int dir[2]);
