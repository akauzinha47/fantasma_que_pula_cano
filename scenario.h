#ifndef SCENARIO
#define SCENARIO

#define WIDTH 40
#define HEIGHT 20
#define SPACE_BTW 5

#include <stdio.h>

void pipe_movement(int matrix[][WIDTH], int x, int y)
{
    // check if the pipe has reached the end of the map
    if (x == 0)
    {
        for (int i = (HEIGHT - y); i < (HEIGHT); i++)
        {
            matrix[i][x] = 0;
            matrix[i][x + 1] = 0;
            matrix[i][x + 2] = 0;
        }

        for (int i = (HEIGHT - y) - SPACE_BTW; i > 0; i--)
        {
            matrix[i][x] = 0;
            matrix[i][x + 1] = 0;
            matrix[i][x + 2] = 0;
        }
        return;
    }
    for (int i = (HEIGHT - y); i < (HEIGHT); i++)
    {
        matrix[i][x - 1] = 1;
        matrix[i][x + 2] = 0;
    }

    for (int i = (HEIGHT - y) - SPACE_BTW; i > 0; i--)
    {
        matrix[i][x - 1] = 1;
        matrix[i][x + 2] = 0;
    }
    
}

void rendering(int matrix[][WIDTH])
{

   
    for (int i = 0; i < WIDTH; i++)
    {
        printf("[]");
    }
    printf("\n");

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (matrix[i][j] == 0)
            {
                printf("  ");
            } else if (matrix[i][j] == 9){
                printf(" X");
            } else {
                printf("[]");

            }
        }
        
    printf("\n");     
    }
}

void restart_pipe(int matrix[][40], int *x, int y)
{
    for (int i = (HEIGHT - y); i < (HEIGHT); i++)
            {
                matrix[i][*x] = 0;
                matrix[i][*x + 1] = 0;
                matrix[i][*x + 2] = 0;
            }

            for (int i = (HEIGHT - y) - SPACE_BTW; i > 0; i--)
            {
                matrix[i][*x] = 0;
                matrix[i][*x + 1] = 0;
                matrix[i][*x + 2] = 0;
            }

            *x = WIDTH - 4;
}

#endif // !SCENARIO