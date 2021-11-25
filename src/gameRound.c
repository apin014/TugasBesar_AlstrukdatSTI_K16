#include"gameRound.h"
#include"readConfig.h"
#include"ADT/mesin_kar.h"
#include"ADT/mesin_kata.h"
#include"ADT/arrayChar.h"
#include"console.h"
#include"mapOperate.h"
#include"skill.h"
#include"buff.h"

void commands(Player *P) {
    boolean hasRolled, hasEndedTurn;
    char *choice;
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
        printf("COMMAND> ");
        STARTKATA();
        choice = (char*)malloc(sizeof(char)*8);
        KataToString(CKata, choice);
        if (strcmp(Roll, choice) == 0) {
            printf("%s memutuskan untuk ROLL\n", PLAYER(P));
            int rollVal;
            if (P->buff[3]) {
                rollVal = roll(1, maxRoll, maxRoll);
            } else if (P->buff[4]) {
                rollVal = roll(2, maxRoll, maxRoll);
            } else {
                rollVal = roll(0, maxRoll, maxRoll);
            }
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
            SKILL(*P);
            free(choice);
        } else if (strcmp(Buff, choice) == 0) {
            BUFF(*P);
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
            printf("COMMAND ERROR, PLEASE TRY AGAIN\n");
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
            printf("%s melakukan end turn\n", PLAYER(P));
            free(choice);
            hasEndedTurn = true;
        } else if (strcmp(Undo, choice) == 0) {
            printf("Mohon maaf, untuk sekarang command ini belum tersedia\n");
            free(choice);
        } else {
            printf("COMMAND ERROR, PLEASE TRY AGAIN\n");
            free(choice);
        }
    }
}

void playRound() {
    AddSkill(&p1);
    commands(&p1);
    AddSkill(&p2);
    commands(&p2);
}