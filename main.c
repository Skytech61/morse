/**
 * @file main.c
 * @author Tuncay
 * @brief 
 * @version 0.1
 * @date 2020-11-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <myconio.h>
#include <ctype.h>
#include <time.h>

#define CONSOLE_WIDTH   120  // default 80
#define CONSOLE_HEIGHT  30  // default 25
#define DIM             40

int main(void)
{    
    char play;
    int i, j, k;
    int returnLineX, returnLineY;
    unsigned char inputText[DIM +1];
    unsigned char symb[] = {
                                'a','.','-','#',
                                'b','-','.','.','.','#',
                                'c','-','.','-','.','#',
                                'd','-','.','.','#',
                                'e','.','#',
                                'f','.','.','-','.','#',
                                'g','-','-','.','#',
                                'h','.','.','.','.','#',
                                'i','.','.','#',
                                'j','.','-','-','-','#',
                                'k','-','.','-','#',
                                'l','.','-','.','.','#',
                                'm','-','-','#',
                                'n','-','.','#',
                                'o','-','-','-','#',
                                'p','.','-','-','.','#',
                                'q','-','-','.','-','#',
                                'r','.','-','.','#',
                                's','.','.','.','#',
                                't','-','#',
                                'u','.','.','-','#',
                                'v','.','.','.','-','#',
                                'w','.','-','-','#',
                                'x','-','.','.','-','#',
                                'y','-','.','-','-','#',
                                'z','-','-','.','.','#',
                                ' ','-','.','.','.','-','#',
                                '0','-','-','-','-','-','#',
                                '1','.','-','-','-','-','#',
                                '2','.','.','-','-','-','#',
                                '3','.','.','.','-','-','#',
                                '4','.','.','.','.','-','#',
                                '5','.','.','.','.','.','#',
                                '6','-','.','.','.','.','.','#',
                                '7','-','-','.','.','.','#',
                                '8','-','-','-','.','.','#',
                                '9','-','-','-','-','.','#'
                            };

    do
    {
        clrscr();

        // Init returned line
        returnLineX = 25;
        returnLineY = 12;

        // Display of additional information
        textattr(BLUE*16 + YELLOW); MYclrwin(1, 1, CONSOLE_WIDTH, CONSOLE_HEIGHT);
        gotoxy(1, 1);
        printf("HELHa");

        gotoxy((CONSOLE_WIDTH - 10), 1);
        printf("Montignies");

        textattr(GREEN*16 + YELLOW); MYclrwin(10, 5, (CONSOLE_WIDTH - 10), 5);
        gotoxy((CONSOLE_WIDTH - 13) / 2, 5);
        printf("LE CODE MORSE");

        // Request essential information
        textattr(LIGHTGRAY*16 + BLACK); MYclrwin(10, 6, (CONSOLE_WIDTH - 10), (CONSOLE_HEIGHT - 5));
        gotoxy(15, 7);
        printf("Message : ");
        gotoxy(18 + 9, 7);
        fflush(stdin);
        scanf("%40[^\n]s", inputText);

        gotoxy((CONSOLE_WIDTH - 12) / 2, 10);
        printf("CODAGE MORSE");

        // Transform inputText in morse
        gotoxy(25, returnLineY);

        for (i = 0; tolower(inputText[i]) != '\0'; i++)
        {
            for (j = 0; j < sizeof(symb); j++)
            {
                if (symb[j] == tolower(inputText[i]))
                {
                    for (k = j + 1; symb[k] != '#'; k++)
                    {
                        printf("%c", symb[k]);
                        Sleep(300);
                    }
                }
            }
            printf("  ");
            if (!((i + 1) % 8)) gotoxy(returnLineX, returnLineY+=2);
        }

        // Ask if we want to play again
        textattr(CYAN*16 + WHITE); MYclrwin(10, (CONSOLE_HEIGHT - 5), (CONSOLE_WIDTH - 10), (CONSOLE_HEIGHT - 5));
        gotoxy((CONSOLE_WIDTH - 20) / 2, (CONSOLE_HEIGHT - 5));
        printf("Recommencer (o/n) ? ");
        fflush(stdin);
        scanf("%c", &play);
    }
    while (tolower(play) == 'o');

    // getch();
    return 0;
}