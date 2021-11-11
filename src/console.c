#include"console.h"
#include<stdlib.h>
#include<stdio.h>

void readConfig (const char *filepath, int *mapSize, char *map, int *maxRoll, int *TeleporterCount, TabInt *TeleportIn, TabInt *TeleportOut) {
    STARTKATA(filepath);
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

void KataToString (Kata K, char *S) {
    for (int i = 1; i <= K.Length; i++)
    {
        S[i-1] = K.TabKata[i];
    }
}