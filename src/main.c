#include"console.c"
#include"readConfig.c"
#include"mapOperate.c"
#include"gameRound.c"
#include"buff.c"
#include"skill.c"
#include"ADT/boolean.h"
#include"ADT/mesin_kar.c"
#include"ADT/mesin_kata.c"
#include"ADT/array.c"
#include"ADT/arrayChar.c"
#include"ADT/listlinier.c"
#include"ADT/player.c"
#include"ADT/state.c"
#include<stdio.h>

int main() {
    do
    {
        menu();
        chooseMode(&gameStatus);
    } while (gameStatus != 1 && gameStatus != 2);
    if (gameStatus == 1) {
        newGame();
        play(&sP1, &sP2, &p1, &p2);
        if (p1.position == NbElmtChar(map)) {
            printf("%s memenangkan permainan!\n", PLAYER(&p1));
        }
        if (p2.position == NbElmtChar(map)) {
            printf("%s memenangkan permainan!\n", PLAYER(&p2));
        }
    } else {
        printf("Game exited\n");
    }

    return 0;
}