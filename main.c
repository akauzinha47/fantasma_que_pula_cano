#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "scenario.h"


int main()
{

    int array[HEIGHT][WIDTH];

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            array[i][j] = 0;
        }
    }

    // array[HEIGHT - 3][8] = 9;

    int y = 8;
    int x1 = WIDTH - 4;
    int x2 = 0;
    int x3 = 0;

    for (int i = (HEIGHT - y); i < (HEIGHT); i++)
    {
        array[i][x1] = 1;
        array[i][x1 + 1] = 1;
        array[i][x1 + 2] = 1;

    }

    for (int i = (HEIGHT - y) - SPACE_BTW; i > 0; i--)
    {
        array[i][x1] = 1;
        array[i][x1 + 1] = 1;
        array[i][x1 + 2] = 1;
    }

    while (1)
    {

        Sleep(200);
        system("cls");

        if (x1 == 0)
        {
            restart_pipe(array, &x1, y);
        }

        if (x2 == 0)
        {
            restart_pipe(array, &x2, y);
        }

        if (x3 == 0)
        {
            restart_pipe(array, &x3, y);
        }

        if (x1 == WIDTH - 16)
        {
            x2 = WIDTH - 4;
        }

        if (x2 == WIDTH - 16)
        {
            x3 = WIDTH - 4;
        }

        if (x2 != 0)
        {
            pipe_movement(array, x2, y);
            x2--;
        }

        if (x3 != 0)
        {
            pipe_movement(array, x3, y);
            x3--;
        }

        if (x1 != 0)
        {
            pipe_movement(array, x1, y);
            x1--;
        }

        rendering(array);
    
    }
  
}

