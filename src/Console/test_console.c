#include"console.h"
#include<stdio.h>
#include<stdlib.h>

int main() {
    do
    {
        menu();
        chooseMode(&gameStatus);
    } while (gameStatus != 1 && gameStatus != 2);
    if (gameStatus == 1) {
        newGame();
    } else {
        printf("Exiting...\n");
    }
    printf("Insert (x/X) to continue\n");
    char c = getchar();
    while (c != 88 && c != 120)
    {
        c = getchar();
    }

    return 0;
}