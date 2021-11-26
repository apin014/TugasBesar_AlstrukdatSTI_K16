#include"gameRound.h"
#include"readConfig.h"
#include"ADT/mesin_kar.h"
#include"ADT/mesin_kata.h"
#include"ADT/arrayChar.h"
#include"console.h"
#include"mapOperate.h"
#include"skill.h"
#include"buff.h"

void commands1(Player *PPrime, Player *PSec, boolean *undoSignal) {
    boolean hasRolled;
    char Roll[] = "ROLL";
    char Skill[] = "SKILL";
    char Buff[] = "BUFF";
    char Map[] = "MAP";
    char Inspect[] = "INSPECT";
    char Undo[] = "UNDO";
    hasRolled = false;
    while (!hasRolled) {
        printf("---------------------------\n|          COMMANDS        |\n---------------------------\n");
        printf("[1] ROLL\n---------------------------\n[2] SKILL\n---------------------------\n[3] BUFF\n---------------------------\n[4] MAP\n---------------------------\n[5] INSPECT\n---------------------------\n[6] UNDO\n---------------------------\n");
        printf("COMMAND> ");
        STARTKATA();
        char *choice = (char*)malloc(sizeof(char)*8);
        KataToString(CKata, choice);
        if (strcmp(Roll, choice) == 0) {
            free(choice);
            roll(PPrime, maxRoll, maxRoll);
            hasRolled = true;
        } else if (strcmp(Skill, choice) == 0) {
            free(choice);
            SKILL(PPrime, PSec);
        } else if (strcmp(Buff, choice) == 0) {
            free(choice);
            BUFF(*PPrime);
        } else if (strcmp(Map, choice) == 0) {
            free(choice);
            printf("%s: ", PLAYER(&p1));
            printMap(map, p1.position);
            printf("%s: ", PLAYER(&p2));
            printMap(map, p2.position);
        } else if (strcmp(Inspect, choice) == 0) {
            free(choice);
            printf("Masukkan petak: ");
            int check;
            scanf("%d", &check);
            inspectTile(check, tIn, tOut);
        } else if (strcmp(Undo, choice) == 0) {
            free(choice);
            *undoSignal = true;
            hasRolled = true;
        } else {
            free(choice);
            printf("COMMAND ERROR, PLEASE TRY AGAIN\n");
        }
    }
    
}

void commands2(Player *PPrime, Player *PSec, boolean *undoSignal) {
    boolean hasEndedTurn;
    char EndTurn[] = "ENDTURN";
    char Undo[] = "UNDO";
    hasEndedTurn = false;
    while (!hasEndedTurn) {
        printf("---------------------------\n|          COMMANDS        |\n---------------------------\n");
        printf("[1] ENDTURN\n---------------------------\n[2] UNDO\n---------------------------\n");
        printf("COMMAND> ");
        STARTKATA();
        char *choice = (char*)malloc(sizeof(char)*8);
        KataToString(CKata, choice);
        if (strcmp(EndTurn, choice) == 0) {
            free(choice);
            printf("%s melakukan end turn\n", PLAYER(PPrime));
            hasEndedTurn = true;
        } else if (strcmp(Undo, choice) == 0) {
            free(choice);
            *undoSignal = true;
            hasEndedTurn = true;
        } else {
            free(choice);
            printf("COMMAND ERROR, PLEASE TRY AGAIN\n");
        }
    }
}

void play(State *SP1, State *SP2, Player *P1, Player *P2) {
    boolean undoSignal, endTurn, finished;
    undoSignal = false;
    finished = false;
    while (!finished)
    {
        endTurn = false;
        while (!endTurn)
        {
            printf("Posisi %s: ", PLAYER(P1));
            printMap(map, P1->position);
            printf("Posisi %s: ", PLAYER(P2));
            printMap(map, P2->position);
            playerTurn(P1, P2, &undoSignal);
            PushPlayer(SP1, *P1);
            if (undoSignal) {
                undo(SP1, SP2, P1, P2);
                undoSignal = false;
            } else {
                endTurn = true;
            }
        }
        if (P1->position == NbElmtChar(map)) {
            finished = true;
            break;
        }
        endTurn = false;
        while (!endTurn)
        {
            printf("Posisi %s: ", PLAYER(P1));
            printMap(map, P1->position);
            printf("Posisi %s: ", PLAYER(P2));
            printMap(map, P2->position);
            playerTurn(P2, P1, &undoSignal);
            PushPlayer(SP2, *P2);
            if (undoSignal) {
                undo(SP1, SP2, P1, P2);
                undoSignal = false;
            }
            endTurn = true;
        }
        if (P2->position == NbElmtChar(map)) {
                finished = true;
                break;
        }
    }
}

void playerTurn(Player *PPrime, Player *PSec, boolean *undoSignal) {
    printf("Sekarang adalah giliran %s\n", PLAYER(PPrime));
    for (int i = 2; i <= 4; i++)
    {
        deactivateBuff(PPrime, i);
    }
    AddSkill(PPrime, 0);
    commands1(PPrime, PSec, undoSignal);
    if (!undoSignal) {
        commands2(PPrime, PSec, undoSignal);
    }
}

void undo(State *SP1, State *SP2, Player *P1, Player *P2) {
    printf("Dilakukan UNDO\n");
    Player pDump;
    PopPlayer(SP1, &pDump);
    PopPlayer(SP2, &pDump);
    if (!IsStateEmpty(*SP1) && !IsStateEmpty(*SP2))
    {
        char opt2;
        printf("Lakukan UNDO lagi? (Masukkan 'y/Y' untuk konfirmasi)\n");
        printf("> ");
        scanf("%c", &opt2);
        while ((opt2 == 'y' || opt2 == 'Y') && (!IsStateEmpty(*SP1) || !IsStateEmpty(*SP2)))
        {
            PopPlayer(SP1, &pDump);
            PopPlayer(SP2, &pDump);
            printf("Lakukan UNDO lagi? (Masukkan 'y/Y' untuk konfirmasi)\n");
            printf("> ");
            scanf("%c", &opt2);
        }
    }
    if (IsStateEmpty(*SP1)) {
        printf("");
        NewPlayer(P1);
    } else if (IsStateEmpty(*SP2)){
        printf("");
        NewPlayer(P2);
    } else {
        *P1 = InfoTop(*SP1);
        *P2 = InfoTop(*SP2);
    }
}