#include"readConfig.h"

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