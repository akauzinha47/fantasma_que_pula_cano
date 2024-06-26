#include <stdio.h>
#include <windows.h>

int main()
{
    int count = 0;

    while (1)
    {
        system("cls"); // Clear screen for Windows (use "clear" for Unix/Linux)

        if (_kbhit())
        {
            char tecla = _getch();

            if (tecla == ' ')
            {
                // Increment count only when spacebar is pressed
                count+=2;
            }
        }
        
        // Remove the decrement statement outside _kbhit block
        // count--; // Remove this line
        count--;
        printf("    %d  ", count);
        Sleep(500); // Adjust sleep time as needed
    }

    return 0;
}