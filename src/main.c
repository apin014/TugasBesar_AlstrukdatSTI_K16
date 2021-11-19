#include"console.c"
#include<stdio.h>

int main() {
    do
    {
        menu();
        chooseMode(&gameStatus);
    } while (gameStatus != 1 && gameStatus != 2 && gameStatus != 3);
    if (gameStatus == 1) {
        printf("New game has been chosen\n");
    } else if (gameStatus == 2) {
        printf("Load game has been chosen\n");
    } else {
        printf("Game exited\n");
    }

    return 0;
}