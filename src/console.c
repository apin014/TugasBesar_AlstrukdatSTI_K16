#include"console.h"
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include"readConfig.h"
#include"mapOperate.h"

int gameStatus, maxRoll, teleporterCount;
TabChar map;
TabInt tIn, tOut;
boolean gameFinished;
Player p1, p2;

void menu() {
    printf("---------------------------\n|        MAIN MENU        |\n---------------------------\n");
    printf("[1] NEW GAME\n---------------------------\n[2] EXIT\n---------------------------\n");
}

void newGame() {
    char filePath[255];
    MakeEmptyChar(&map);
    MakeEmpty(&tIn); MakeEmpty(&tOut);
    printf("---------------------------\nInput config file path: ");
    STARTKATA();
    KataToString(CKata, filePath);
    readConfig(filePath, &map, &maxRoll, &teleporterCount, &tIn, &tOut);
    NewPlayer(&p1); NewPlayer(&p2);
    printf("---------------------------\nPlayer 1 name> ");
    STARTKATA();
    KataToString(CKata, p1.name);
    printf("---------------------------\nPlayer 2 name> ");
    STARTKATA();
    KataToString(CKata, p2.name);
    gameFinished = false;
    printf("Permainan dimulai dengan 2 orang pemain\n");
    printf("Mapsize: %d\n", NbElmtChar(map));
    printf("Posisi %s: ", PLAYER(&p1));
    printMap(map, p1.position);
    printf("Posisi %s: ", PLAYER(&p2));
    printMap(map, p2.position);
    printf("Max roll: %d\n", maxRoll);
    printf("Teleporter count: %d\n", teleporterCount);
    printf("Pintu masuk teleporter: \n");
    printf("[");
    for (int i = 1; i <= NbEl(tIn); i++)
    {
        printf(" %d ", GetElmt(tIn, i));
    }
    printf("]\n");
    printf("Pintu keluar teleporter: \n");
    printf("[");
        for (int i = 1; i <= NbEl(tOut); i++)
    {
        printf(" %d ", GetElmt(tOut, i));
    }
    printf("]\n");
}

void chooseMode(int *spec) {
    printf("> ");
    START();
    switch (CC)
    {
    case '1':
        *spec = 1;
        break;

    case '2':
        *spec = 2;
        break;

    default:
        break;
    }
}