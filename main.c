#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "scenario.h"
#include "structs.h"


int main()
{

    // inicializa a matriz com uma largura WIDTH e uma altura HEIGHT
    int array[HEIGHT][WIDTH];

    // torna seus valores iguais à zero
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            array[i][j] = 0;
        }
    }

    // "instancia" três obstáculos 
    Pipe first_pipe = construct_pipe();
    Pipe second_pipe = construct_pipe(); 
    Pipe third_pipe = construct_pipe(); 

    Sleep(200);

    int y1  = 5;
    int y2  = 13;
    int y3  = 9;

    first_pipe.x = WIDTH - 4;
    first_pipe.y = y1;

    second_pipe.x = -1;
    third_pipe.x = -1;

    // inicializa o primeiro obstáculo
    for (int i = (HEIGHT - y1); i < (HEIGHT); i++)
    {
        array[i][first_pipe.x] = 1;
        array[i][first_pipe.x + 1] = 1;
        array[i][first_pipe.x + 2] = 1;

    }

    for (int i = (HEIGHT - y1) - SPACE_BTW; i > 0; i--)
    {
        array[i][first_pipe.x] = 1;
        array[i][first_pipe.x + 1] = 1;
        array[i][first_pipe.x + 2] = 1;
    }

    while (1)
    {
        
        Sleep(600);
        system("cls");

        if (first_pipe.x == 0)
        {
            restart_pipe(array, &first_pipe);
        }

        if (second_pipe.x == 0)
        {
            restart_pipe(array, &second_pipe);
        }

        if (third_pipe.x == 0)
        {
            restart_pipe(array, &third_pipe);
        }

        if (first_pipe.x == WIDTH - 16)
        {
            second_pipe.x = WIDTH - 4;
            second_pipe.y = y2;
        }

        if (second_pipe.x == WIDTH - 16)
        {
            third_pipe.x = WIDTH - 4;
            third_pipe.y = y3;
        }

        if (first_pipe.x > 0)
        {
            pipe_movement(array, &first_pipe);
            first_pipe.x--;
        }

        if (second_pipe.x > 0)
        {
            pipe_movement(array, &second_pipe);
            second_pipe.x--;
        }

        if (third_pipe.x > 0)
        {
            pipe_movement(array, &third_pipe);
            third_pipe.x--;
        }

        printf("%d - %d - %d\n", first_pipe.x, second_pipe.x, third_pipe.x);
        rendering(array);
    
    }
  
}

