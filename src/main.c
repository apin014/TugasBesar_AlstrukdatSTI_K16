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
            printf("%s telah mencapai petak terakhir lebih dulu,\n%smemenangkan permainan!\n", PLAYER(&p1), PLAYER(&p1));
            printf("Peringkat:\n1. %s\n2. %s\n", PLAYER(&p1), PLAYER(&p2));
        }
        if (p2.position == NbElmtChar(map)) {
            printf("%s telah mencapai petak terakhir lebih dulu,\n%smemenangkan permainan!\n", PLAYER(&p2), PLAYER(&p2));
            printf("Peringkat:\n1. %s\n2. %s\n", PLAYER(&p2), PLAYER(&p1));
        }
    } else {
        printf("Keluar dari game\n");
    }

    return 0;
}