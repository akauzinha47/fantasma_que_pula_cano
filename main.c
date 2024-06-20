#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define WIDTH 20
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
    int x1 = WIDTH - 3;
    int x2 = 0;

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

        if (x1 == 0)
        {
            for (int i = (HEIGHT - y); i < (HEIGHT); i++)
            {
                array[i][x1] = 0;
                array[i][x1 + 1] = 0;
                array[i][x1 + 2] = 0;
            }

            for (int i = (HEIGHT - y) - SPACE_BTW; i > 0; i--)
            {
                array[i][x1] = 0;
                array[i][x1 + 1] = 0;
                array[i][x1 + 2] = 0;
            }

            x1 = WIDTH - 3;
        }



        for (x1; x1 > 0; x1--)
        {
            if (x2 == 0)
            {
                printf("X2 = 0 MANO\n");
                for (int i = (HEIGHT - y); i < (HEIGHT); i++)
                {
                    array[i][x2] = 0;
                    array[i][x2 + 1] = 0;
                    array[i][x2 + 2] = 0;
                }

                for (int i = (HEIGHT - y) - SPACE_BTW; i > 0; i--)
                {
                    array[i][x2] = 0;
                    array[i][x2 + 1] = 0;
                    array[i][x2 + 2] = 0;
                }

            }
            if (x1 == WIDTH / 2)
            {
                x2 = WIDTH - 3;
            }

            if (x2 != 0)
            {
                for (int i = (HEIGHT - y); i < (HEIGHT); i++)
                {

                    array[i][x2 - 1] = 1;
                    array[i][x2 + 2] = 0;
                }

                for (int i = (HEIGHT - y) - SPACE_BTW; i > 0; i--)
                {
                    array[i][x2 - 1] = 1;
                    array[i][x2 + 2] = 0;
                }

                x2--;
            }

            sleep(1);
            system("cls");

            for (int i = (HEIGHT - y); i < (HEIGHT); i++)
            {

                array[i][x1 - 1] = 1;
                array[i][x1 + 2] = 0;
            }

            for (int i = (HEIGHT - y) - SPACE_BTW; i > 0; i--)
            {
                array[i][x1 - 1] = 1;
                array[i][x1 + 2] = 0;
            }

            printf("%d - %d\n", x1, x2);
            for (int i = 0; i < WIDTH; i++)
            {
                printf("[]");
            }
            printf("\n");

            for (int x1 = 0; x1 < HEIGHT; x1++)
            {
                for (int j = 0; j < WIDTH; j++)
                {
                    if (array[x1][j] == 0)
                    {
                        printf("  ");
                    } else if (array[x1][j] == 9){
                        printf(" X");
                    } else {
                        printf("[]");

                    }
                }
                
            printf("\n");
            }
    
        }
        
    }
}

