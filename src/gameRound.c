#include"gameRound.h"
#include"readConfig.h"
#include"ADT/mesin_kar.h"
#include"ADT/mesin_kata.h"
#include"ADT/arrayChar.h"
#include"console.h"
#include"mapOperate.h"
#include"skill.h"
#include"buff.h"

void commands(Player *PPrime, Player *PSec) {
    boolean hasRolled, hasEndedTurn;
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
        char *choice = (char*)malloc(sizeof(char)*8);
        KataToString(CKata, choice);
        if (strcmp(Roll, choice) == 0) {
            roll(PPrime, maxRoll, maxRoll);
            free(choice);
            hasRolled = true;
        } else if (strcmp(Skill, choice) == 0) {
            SKILL(PPrime, PSec);
            free(choice);
        } else if (strcmp(Buff, choice) == 0) {
            BUFF(*PPrime);
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
        printf("COMMAND> ");
        STARTKATA();
        char *choice = (char*)malloc(sizeof(char)*8);
        KataToString(CKata, choice);
        if (strcmp(EndTurn, choice) == 0) {
            printf("%s melakukan end turn\n", PLAYER(PPrime));
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
    boolean gameFinished = false;
    int round = 1;
    while (!gameFinished) {
        printf("############ ROUND %d ############\n", round);
        printf("Posisi %s: ", PLAYER(&p1));
        printMap(map, p1.position);
        printf("Posisi %s: ", PLAYER(&p2));
        printMap(map, p2.position);
        for (int i = 2; i <= 4; i++)
        {
            deactivateBuff(&p1, i);
        }
        AddSkill(&p1, 0);
        commands(&p1, &p2);
        if (p1.position == NbElmtChar(map)) {
            gameFinished = true;
            break;
        }
        printf("Posisi %s: ", PLAYER(&p1));
        printMap(map, p1.position);
        printf("Posisi %s: ", PLAYER(&p2));
        printMap(map, p2.position);
        for (int i = 2; i <= 4; i++)
        {
            deactivateBuff(&p2, i);
        }
        AddSkill(&p2, 0);
        commands(&p2, &p1);
        if (p2.position == NbElmtChar(map)) {
            gameFinished = true;
            break;
        }
        round++;
    }
    if (p1.position == NbElmtChar(map)) {
        printf("%s adalah pemenangnya\n", PLAYER(&p1));
    } else {
        printf("%s adalah pemenangnya\n", PLAYER(&p2));
    }
}