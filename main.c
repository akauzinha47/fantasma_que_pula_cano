#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define WIDTH 40
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

        sleep(1);
        system("cls");

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

            x1 = WIDTH - 4;
        }



        if (x2 == 0)
        {
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

        if (x3 == 0)
        {
            for (int i = (HEIGHT - y); i < (HEIGHT); i++)
            {
                array[i][x3] = 0;
                array[i][x3 + 1] = 0;
                array[i][x3 + 2] = 0;
            }

            for (int i = (HEIGHT - y) - SPACE_BTW; i > 0; i--)
            {
                array[i][x3] = 0;
                array[i][x3 + 1] = 0;
                array[i][x3 + 2] = 0;
            }

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

            if (x3 != 0)
        {
            for (int i = (HEIGHT - y); i < (HEIGHT); i++)
            {

                array[i][x3 - 1] = 1;
                array[i][x3 + 2] = 0;
            }

            for (int i = (HEIGHT - y) - SPACE_BTW; i > 0; i--)
            {
                array[i][x3 - 1] = 1;
                array[i][x3 + 2] = 0;
            }

            x3--;
        }
        

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

        x1--;

        printf("%d - %d - %d\n", x1, x2, x3);
        for (int i = 0; i < WIDTH; i++)
        {
            printf("[]");
        }
        printf("\n");

        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                if (array[i][j] == 0)
                {
                    printf("  ");
                } else if (array[i][j] == 9){
                    printf(" X");
                } else {
                    printf("[]");

                }
            }

            // for (int j = 0; j < WIDTH; j++)
            // {
            //     printf("%d", array[i][j]);
            // }
            
        printf("\n");     
        }
    
    }
  
}

