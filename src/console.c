#include"console.h"
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>

Kata CKata;
boolean EndKata;

void readConfig (const char *filepath, TabChar *map, int *maxRoll, int *TeleporterCount, TabInt *TeleportIn, TabInt *TeleportOut) {
    STARTKATAFILE(filepath);
    ADVKATA();
    SetNeffChar(map, CKata.Length);
    for (int i = 1; i <= CKata.Length; i++)
    {
        SetElChar(map, i, CKata.TabKata[i]);
    }
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
        if (El >= 10) {
            if (El >= 100) {
                if (CKata.Length < 3) {
                    if (CKata.Length == 2) {
                        El /= 10;
                    } else {
                        El /= 100;
                    }
                }   
            } else {
                if (CKata.Length < 2) {
                    El /= 10;
                }
            }
        }
        if (i % 2 != 0) {
            SetEl(TeleportIn, (i+1)/2, El);
        } else {
            SetEl(TeleportOut, i/2, El);
        }
        free(strEl);
        i++;
    }
}

void menu() {
    printf("---------------------------\n|        MAIN MENU        |\n---------------------------\n");
    printf("[1] NEW GAME\n---------------------------\n[2] LOAD GAME\n---------------------------\n[3] EXIT\n---------------------------\n");
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

    case '3':
        *spec = 3;
        break;

    default:
        break;
    }
}

int roll(int buffStat, int maxRoll, unsigned int seedOffSet) {
    srand(time(NULL) - seedOffSet);
    unsigned int seed = (unsigned) rand();
    srand(seed);
    switch (buffStat)
    {
    case 0:
        return (rand() % maxRoll) + 1;
    
    case 1:
        return (rand() % (maxRoll + 1 - (int)floor(maxRoll/2))) + (int)floor(maxRoll/2);

    case 2:
        return (rand() % (int)floor(maxRoll/2)) + 1;

    default:
        break;
    }
}