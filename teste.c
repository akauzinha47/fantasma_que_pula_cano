#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define WIDTH 50
#define HEIGHT 20
#define SPACE_BTW 5

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
    int x = 30;

    for (int i = (HEIGHT - y); i < (HEIGHT); i++)
    {
        array[i][x] = 1;
        printf("%d - %d - %d\n", i, x - 1, array[i][x - 1]);
        array[i][x + 1] = 1;
        array[i][x + 2] = 1;

    }

    for (int i = (HEIGHT - y) - SPACE_BTW; i > 0; i--)
    {
        array[i][x] = 1;
        printf("%d - %d - %d\n", i, x - 1, array[i][x - 1]);
        array[i][x + 1] = 1;
        array[i][x + 2] = 1;
    }

    for (x; x > 0; x--)
    {
        sleep(1);
        system("cls");

        for (int i = (HEIGHT - y); i < (HEIGHT); i++)
        {

            array[i][x - 1] = 1;
            array[i][x + 2] = 0;
        }

        for (int i = (HEIGHT - y) - SPACE_BTW; i > 0; i--)
        {
            array[i][x - 1] = 1;
            array[i][x + 2] = 0;
        }

        for (int x = 0; x < HEIGHT; x++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                if (array[x][j] == 0)
                {
                    printf("  ");
                } else if (array[x][j] == 9){
                    printf("X");
                } else {
                    printf("[]");
                }
            }
            
        printf("\n");
        }
 
    }

    // array[HEIGHT - y][(x - 1) - 1] = 1;
    // array[HEIGHT - y][x - 1] = 0;
        
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ");
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (array[i][j] == 0)
            {
                printf("  ");
            } else{
                printf("[] ");
            }
        }
        printf("\n");
    }
}