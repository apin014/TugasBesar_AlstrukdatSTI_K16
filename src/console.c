#include"console.h"
#include<stdlib.h>
#include<stdio.h>

Kata CKata;
boolean EndKata;

void readConfig (const char *filepath, int *mapSize, char *map, int *maxRoll, int *TeleporterCount, TabInt *TeleportIn, TabInt *TeleportOut) {
    STARTKATAFILE(filepath);
    char strMapSize[CKata.Length];
    KataToString(CKata, strMapSize);
    sscanf(strMapSize, "%d", mapSize);
    ADVKATA();
    KataToString(CKata, map);
    ADVKATA();
    char strMaxRoll[CKata.Length];
    KataToString(CKata, strMaxRoll);
    sscanf(strMaxRoll, "%d", maxRoll);
    ADVKATA();
    char strTeleporterCount[CKata.Length];
    KataToString(CKata, strTeleporterCount);
    sscanf(strTeleporterCount, "%d", TeleporterCount);
    SetNeff(TeleportIn, *TeleporterCount); SetNeff(TeleportOut, *TeleporterCount);
    int i = 1;
    while (!EndKata)
    {
        ADVKATA();
        char *strEl = (char*)malloc(sizeof(char)*CKata.Length);
        KataToString(CKata, strEl);
        int El;
        sscanf(strEl, "%d", &El);
        if (i % 2 != 0) {
            SetEl(TeleportIn, (i+1)/2, El);
        } else {
            SetEl(TeleportOut, i/2, El);
        }
        free(strEl);
        i++;
    }
}