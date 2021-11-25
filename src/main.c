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
#include<stdio.h>

int main() {
    do
    {
        menu();
        chooseMode(&gameStatus);
    } while (gameStatus != 1 && gameStatus != 2);
    if (gameStatus == 1) {
        newGame();
        playRound();
    } else {
        printf("Game exited\n");
    }
    fclose(pita);

    return 0;
}