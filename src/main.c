#include"Console/console.h"
#include"ConfigReader/readConfig.h"
#include"MapOperating/mapOperate.h"
#include"GameRound/gameRound.h"
#include"Buff/buff.h"
#include"Skill/skill.h"
#include"ADT/boolean.h"
#include"ADT/mesin_kar.h"
#include"ADT/mesin_kata.h"
#include"ADT/array.h"
#include"ADT/arrayChar.h"
#include"ADT/listlinier.h"
#include"ADT/player.h"
#include"ADT/state.h"
#include<stdio.h>
#include<stdlib.h>

void welcome(FILE *fp);

int main() {
    char *welcomeText = "..\\data\\welcome_text.txt";
    FILE *fp = NULL;
    fp = fopen(welcomeText, "r");
    if (fp != NULL) {
        welcome(fp);
    }

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
    printf("Insert (x/X) to continue\n");
    char c = getchar();
    while (c != 88 && c != 120)
    {
        c = getchar();
    }

    return 0;
}

void welcome(FILE *fp) {
    char read_string[255];
    while(fgets(read_string, sizeof(read_string), fp) != NULL) {
        printf("%s",read_string);
    }
}