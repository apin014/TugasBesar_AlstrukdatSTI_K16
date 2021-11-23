#include"console.c"
#include"ADT/boolean.h"
#include"ADT/mesin_kar.c"
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
            if (p1.position == NbElmtChar(map) || p2.position == NbElmtChar(map)) {
                gameFinished = true;
            }
        }
        if (p1.position == NbElmtChar(map)) {
            printf("%s adalah pemenangnya\n", PLAYER(&p1));
        } else {
            printf("%s adalah pemenangnya\n", PLAYER(&p2));
        }
    } else {
        printf("Game exited\n");
    }

    return 0;
}