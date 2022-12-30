#include "Functions.h"

void ShowLabyrinth(unsigned int labyrinth[LABHEIGHT][LABWIDTH])
{
    for (int i = 0; i < LABHEIGHT; ++i)
    {
        for (int j = 0; j < LABWIDTH;    ++j)
        {
            printf("%d ", labyrinth[i][j]);
        }

        printf("\n");
    }
}

int FindStart(unsigned int labyrinth[LABHEIGHT][LABWIDTH], unsigned int position[2])
{
    for (int i = 0; i < LABHEIGHT; ++i)
    {
        for (int j = 0; j < LABWIDTH; ++j)
        {
            if (labyrinth[i][j] == ENTRYCODE)
            {
                position[0] = i;
                position[1] = j;
                return 1;
            }
        }
    }

    printf("Could not find an entry code, please ensure you have used the correct code for it.\n");
    return 0;
}

int HasFinish(unsigned int labyrinth[LABHEIGHT][LABWIDTH])
{
    for (int i = 0; i < LABHEIGHT; ++i)
    {
        for (int j = 0; j < LABWIDTH; ++j)
        {
            if (labyrinth[i][j] == ENTRYCODE)
            {
                return 1;
            }
        }
    }

    printf("Could not find a finish code, please ensure you have used the correct code for it.\n");
    return 0;
}

void RotateLeft(int direction[2]){
    // FORWARD -> LEFT
    // LEFT -> BACKWARD
    // BACKWARD -> RIGHT
    // RIGHT -> FORWARD

    // FORWARD = {-1, 0}
    // BACKWARD = {1, 0}
    // LEFT = {0, -1}
    // RIGHT = {0, 1}

    //FORWARD or BACKWARD
    if (direction[1] == 0)
    {
        direction[1] = direction[0];
        direction[0] = 0;
    } 
    // RIGHT or LEFT
    else {
        direction[0] = direction[1] * (-1);
        direction[1] = 0;
    }
}

void RotateRight(int direction[2]){
    // FORWARD -> RIGHT
    // RIGHT -> BACKWARD
    // BACKWARD -> LEFT
    // LEFT -> FORWARD

    // FORWARD = {-1, 0}
    // BACKWARD = {1, 0}
    // LEFT = {0, -1}
    // RIGHT = {0, 1}

    //FORWARD or BACKWARD
    if (direction[1] == 0)
    {
        direction[1] = direction[0] * (-1);
        direction[0] = 0;
    } 
    // RIGHT or LEFT
    else {
        direction[0] = direction[1];
        direction[1] = 0;
    }
}

void Move(unsigned int labyrinth[LABHEIGHT][LABWIDTH], unsigned int position[2], int dir[])
{
    // Check if we are on the finish cell.
    if (labyrinth[position[0]][position[1]] == FINISHCODE)
    {
        return;
    } 
    else 
    {
        RotateLeft(dir);
        
        // nextCell created to get the value of the next cell in our direction of movement.
        unsigned int nextCell = labyrinth[position[0] + dir[0]] [position[1] + dir[1]];

        while (nextCell != EMPTYCELL && nextCell != FINISHCODE)
        {
            RotateRight(dir);
            nextCell = labyrinth[position[0] + dir[0]] [position[1] + dir[1]];
        }
        
        // Make one step in our direction.
        position[0] += dir[0];
        position[1] += dir[1];
        
        printf("direction: (%d, %d)\n", dir[0], dir[1]);
        printf("new position: (%d, %d)\n", position[0]+1, position[1]+1);
        // system("pause");

        Move(labyrinth, position, dir);
    }
}
