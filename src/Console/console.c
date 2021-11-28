#include"console.h"
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include"../ConfigReader/readConfig.h"

int gameStatus, maxRoll, teleporterCount;
TabChar map;
TabInt tIn, tOut;
Player p1, p2;
State sP1, sP2;

void menu() {
    printf("---------------------------\n|        MAIN MENU        |\n---------------------------\n");
    printf("[1] NEWGAME\n---------------------------\n[2] EXIT\n---------------------------\n");
}

void newGame() {
    MakeEmptyChar(&map);
    MakeEmpty(&tIn); MakeEmpty(&tOut);
    printf("---------------------------\nInput config file path: ");
    STARTNAME();
    char *filePath = (char*) malloc (sizeof(char) * CKata.Length+1);
    KataToString(CKata, filePath);
    printf("%s\n", filePath);
    readConfig(filePath, &map, &maxRoll, &teleporterCount, &tIn, &tOut);
    free(filePath);
    NewPlayer(&p1); NewPlayer(&p2);
    printf("---------------------------\nPlayer 1 name> ");
    STARTNAME();
    KataToString(CKata, p1.name);
    printf("---------------------------\nPlayer 2 name> ");
    STARTNAME();
    KataToString(CKata, p2.name);
    CreateEmptyState(&sP1); CreateEmptyState(&sP2);
    printf("---------------------------\nPermainan dimulai dengan 2 orang pemain\n");
    printf("Ukuran map: %d\n", NbElmtChar(map));
    printf("Max roll: %d\n", maxRoll);
    printf("Jumlah Teleporter: %d\n", teleporterCount);
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
    char newGame[] = "NEWGAME";
    char exit[] = "EXIT";
    char *mode = (char*) malloc (CKata.Length+1);
    printf("> ");
    STARTKATA();
    KataToString(CKata, mode);
    if (strcmp(newGame, mode) == 0) {
        *spec = 1;
    } else if (strcmp(exit, mode) == 0) {
        *spec = 2;
    }
    free(mode);
}