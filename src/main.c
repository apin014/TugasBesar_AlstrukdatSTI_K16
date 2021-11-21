#include"console.c"
#include"ADT/boolean.h"
#include"ADt/mesin_kar.c"
#include"ADT/mesin_kata.c"
#include"ADT/array.c"
#include"ADT/arrayChar.c"
#include"ADT/listlinier.c"
#include"ADT/player.c"
#include<stdio.h>

int main() {
    do
    {
        menu();
        chooseMode(&gameStatus);
    } while (gameStatus != 1 && gameStatus != 2);
    if (gameStatus == 1) {
        newGame();
        while (!gameFinished) {
            playRound();
            gameFinished = true;
        }
    } else {
        printf("Game exited\n");
    }

    return 0;
}