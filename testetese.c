// #include <stdio.h>
// #include <stdlib.h>
// #include <conio.h>
// #include <windows.h>

// #define LARGURA_TERMINAL 20
// #define ALTURA_TERMINAL 40
// #define BONECO "^~^"

// struct 
// {
//     int x, y;
//     int pulando;
// } boneco;

// void configurar_tamanho_console() 
// {
//     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//     COORD tamanho = { LARGURA_TERMINAL, ALTURA_TERMINAL };
//     SetConsoleScreenBufferSize(hConsole, tamanho);

//     SMALL_RECT retangulo;
//     retangulo.Left = 0;
//     retangulo.Top = 0;
//     retangulo.Right = LARGURA_TERMINAL - 1;
//     retangulo.Bottom = ALTURA_TERMINAL - 1;
//     SetConsoleWindowInfo(hConsole, TRUE, &retangulo);
// }

// void mover_cursor(int x, int y) 
// {
//     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//     COORD posicao = { x, y };
//     SetConsoleCursorPosition(hConsole, posicao);
// }

// void limpar_terminal() 
// {
//     system("cls");
// }

// void desenhar_boneco() 
// {
//     mover_cursor(boneco.x, boneco.y);
//     printf("%s", BONECO);
//     fflush(stdout);
// }

// void apagar_boneco() 
// {
//     mover_cursor(boneco.x, boneco.y);
//     printf("   ");
//     fflush(stdout);
// }

// int main() 
// {

//     configurar_tamanho_console();

//     boneco.x = 0;  
//     boneco.y = ALTURA_TERMINAL / 2;  
//     boneco.pulando = 0;

//     int pulo_atual = 0;  

//     while (1) 
//     {
//         limpar_terminal();
        // desenhar_boneco();

//         if (_kbhit()) 
//         {
//             char tecla = _getch();

//             if (tecla == ' ') 
//             {             
//                 if (!boneco.pulando) 
//                 {
//                     boneco.pulando = 1;  
//                     pulo_atual = 0;  
//                 }
//             }
//         }

//         if (boneco.pulando) 
//         {
//             apagar_boneco();
//             if (pulo_atual < 3)  
//             {
//                 if (boneco.y > 0) 
//                 {
//                     boneco.y--;  
//                     pulo_atual++;
//                 }
//                 else
//                 {
//                     boneco.pulando = 0;
//                 }
//             }
//             else
//             {
//                 boneco.pulando = 0;  
//             }
//         }
//         else
//         {
//             if (boneco.y < ALTURA_TERMINAL - 1) {
//                 boneco.y++;  
//             }
//         }

//        
//         Sleep(5000);  
//     }

//     return 0;
// }
