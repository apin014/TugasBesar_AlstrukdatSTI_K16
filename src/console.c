#include"console.h"
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<string.h>

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

void printMap(TabChar map, int playerPosition) {
    for (int i = 1; i <= NbElmtChar(map); i++)
    {
        if (i != playerPosition) {
            printf("%c", GetElmtChar(map, i));
        } else {
            printf("%c", '*');
        }
    }
    printf(" %d\n", playerPosition);
}

void inspectTile(int tile, TabInt teleporterIn, TabInt teleporterOut) {
    IdxType i = GetIdx(teleporterIn, tile);
    if (i != IdxUndef) {
        printf("Petak %d memiliki teleporter dengan pintu keluar di petak %d\n", tile, GetElmt(teleporterOut, i));
    } else {
        printf("Petak %d merupakan petak kosong\n", tile);
    }
}

void commands(Player *P) {
    boolean hasRolled, hasEndedTurn;
    int choice;
    char Roll[] = "ROLL";
    char Skill[] = "SKILL";
    char Buff[] = "BUFF";
    char Map[] = "MAP";
    char Inspect[] = "INSPECT";
    char Undo[] = "UNDO";
    char EndTurn[] = "ENDTURN";
    hasRolled = false;
    hasEndedTurn = false;
    while (!hasRolled) {
        printf("---------------------------\n|          COMMANDS        |\n---------------------------\n");
        printf("[1] ROLL\n---------------------------\n[2] SKILL\n---------------------------\n[3] BUFF\n---------------------------\n[4] MAP\n---------------------------\n[5] INSPECT\n---------------------------\n[6] UNDO\n---------------------------\n");
        printf("> ");
        STARTKATA();
        char *choice = (char*)malloc(sizeof(char)*8);
        KataToString(CKata, choice);
        if (strcmp(Roll, choice) == 0) {
            printf("%s memutuskan untuk ROLL\n", PLAYER(P));
            int rollVal = roll(0, maxRoll, P->position);
            printf("Roll value: %d\n", rollVal);
            if (P->position + rollVal <= NbElmtChar(map) && GetElmtChar(map, P->position + rollVal) != '#') {
                printf("%s dapat maju\n", PLAYER(P));
                if (P->position - rollVal >= 1 && GetElmtChar(map, P->position - rollVal) != '#') {
                    printf("%s dapat mundur\n", PLAYER(P));
                    int move = -999;
                    while (move != 1 && move != 2) {
                        printf("1. Maju ke %d\n2. Mundur ke %d\n", P->position+rollVal, P->position-rollVal);
                        chooseMode(&move);
                    }
                    if (move == 1) {
                        P->position += rollVal;
                        printf("%s maju ke %d\n", PLAYER(P),  P->position);
                    } else if (move == 2) {
                        P->position -= rollVal;
                        printf("%s mundur ke %d\n", PLAYER(P),  P->position);
                    }
                } else {
                    P->position += rollVal;
                    printf("%s maju ke %d\n", PLAYER(P),  P->position);
                }
                teleport(&(P->position), tIn, tOut);
            } else {
                if (P->position - rollVal >= 1 && GetElmtChar(map, P->position - rollVal) != '#') {
                    printf("%s dapat mundur\n", PLAYER(P));
                    P->position -= rollVal;
                    printf("%s mundur ke %d\n", PLAYER(P),  P->position);
                    teleport(&(P->position), tIn, tOut);
                } else {
                    printf("%s tidak bisa bergerak ke mana-mana\n", PLAYER(P));
                }
            }
            printf("Posisi %s sekarang ada di petak %d\n", PLAYER(P), P->position);
            free(choice);
            hasRolled = true;
        } else if (strcmp(Skill, choice) == 0) {
            printf("%s melihat SKILLS\n", PLAYER(P));
            free(choice);
        } else if (strcmp(Buff, choice) == 0) {
            printf("%s melihat BUFFS\n", PLAYER(P));
            free(choice);
        } else if (strcmp(Map, choice) == 0) {
            printf("%s: ", PLAYER(&p1));
            printMap(map, p1.position);
            printf("%s: ", PLAYER(&p2));
            printMap(map, p2.position);
            free(choice);
        } else if (strcmp(Inspect, choice) == 0) {
            printf("Masukkan petak: ");
            int check;
            scanf("%d", &check);
            inspectTile(check, tIn, tOut);
            free(choice);
        } else if (strcmp(Undo, choice) == 0) {
            printf("Mohon maaf, untuk sekarang command ini belum tersedia\n");
            free(choice);
        } else {
            printf("COMMAND UNDEFINED\n");
            free(choice);
        }
    }
    while (!hasEndedTurn) {
        printf("---------------------------\n|          COMMANDS        |\n---------------------------\n");
        printf("[1] ENDTURN\n---------------------------\n[2] UNDO\n---------------------------\n");
        printf("> ");
        STARTKATA();
        char *choice = (char*)malloc(sizeof(char)*8);
        KataToString(CKata, choice);
        if (strcmp(EndTurn, choice) == 0) {
            printf("%s ended turn\n", PLAYER(P));
            free(choice);
            hasEndedTurn = true;
        } else if (strcmp(Undo, choice) == 0) {
            printf("Mohon maaf, untuk sekarang command ini belum tersedia\n");
            free(choice);
        } else {
            printf("COMMAND UNDEFINED, PLEASE TRY AGAIN\n");
            free(choice);
        }
    }
}

void playRound() {
    commands(&p1);
    commands(&p2);
}

void teleport(int *position, TabInt teleporterIn, TabInt teleporterOut) {
    IdxType i = GetIdx(teleporterIn, *position);
    if (i != IdxUndef) {
        int teleportPos = GetElmt(teleporterOut, i);
        printf("Terjadi teleportasi ke %d\n", teleportPos);
        *position = teleportPos;
    } else {
        printf("Tidak terjadi teleportasi\n");
    }
}