#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "scenario.h"
#include "structs.h"

int main()
{

    // inicializa a matriz com uma largura WIDTH e uma altura HEIGHT
    int map[HEIGHT][WIDTH];

    // torna seus valores iguais à zero
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            map[i][j] = 0;
        }
    }

    // "instancia" três obstáculos 
    Pipe first_pipe = construct_pipe();
    Pipe second_pipe = construct_pipe(); 
    Pipe third_pipe = construct_pipe(); 

    // instancia o mucego
    Bat bat = construct_bat();

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
        map[i][first_pipe.x] = 1;
        map[i][first_pipe.x + 1] = 1;
        map[i][first_pipe.x + 2] = 1;

    }

    for (int i = (HEIGHT - y1) - SPACE_BTW; i >= 0; i--)
    {
        map[i][first_pipe.x] = 1;
        map[i][first_pipe.x + 1] = 1;
        map[i][first_pipe.x + 2] = 1;
    }

    // inicializa o primeiro obstáculo

    int jump = 0;
    int n_jumps = 0;

    while (1)
    {

                // Check for keyboard input
        if (_kbhit())
        {
            char tecla = _getch();

            if (tecla == 'W')
            {
                 if (jump == 0)
                {
                    jump++;
                    n_jumps = 3;
                }
            }
        }

        if (jump > 3)
        {
            jump = 3;
        }

        if (jump != 0 && n_jumps > 0)
        {
            flap(map, &bat);
            n_jumps--;
        }

        if (n_jumps == 0)
        {
            jump = 0;
        }

        map[bat.y][bat.x] = BAT_VALUE;
        Sleep(300);
        system("cls");

        if (first_pipe.x == 0)
        {
            restart_pipe(map, &first_pipe);
        }

        if (second_pipe.x == 0)
        {
            restart_pipe(map, &second_pipe);
        }

        if (third_pipe.x == 0)
        {
            restart_pipe(map, &third_pipe);
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
            pipe_movement(map, &first_pipe);
            first_pipe.x--;
        }

        if (second_pipe.x > 0)
        {
            pipe_movement(map, &second_pipe);
            second_pipe.x--;
        }

        if (third_pipe.x > 0)
        {
            pipe_movement(map, &third_pipe);
            third_pipe.x--;
        }

        gravity(map, &bat);

        printf("%d - %d - %d | %d - %d - %d\n", first_pipe.x, second_pipe.x, third_pipe.x, bat.y, jump, n_jumps);
        rendering(map);
    
    }
  
}

