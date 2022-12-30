#include "Functions.h"

int main()
{
    unsigned int labyrinth[LABHEIGHT][LABWIDTH] = {
                                                    {1, 1, 1, 1, 1},
                                                    {1, 0, 0, 0, 1},
                                                    {1, 0, 1, 0, 8},
                                                    {1, 0, 1, 1, 1},
                                                    {1, 7, 1, 1, 1},
                                                  };

    unsigned int position[2];

    // FORWARD = {-1, 0}
    // BACKWARD = {1, 0}
    // LEFT = {0, -1}
    // RIGHT = {0, 1}
    int dir[2] = {-1, 0};

    ShowLabyrinth(labyrinth);

    // Check that we have start cell.
    if (FindStart(labyrinth, position) == 0) { return 1; }
    printf("\nStart position: (%d, %d)\n", position[0] + 1, position[1] + 1);

    // Check that we have finish cell.
    if (HasFinish(labyrinth) == 0) { return 2; }

    Move(labyrinth, position, dir);
    
    system("pause");
}
