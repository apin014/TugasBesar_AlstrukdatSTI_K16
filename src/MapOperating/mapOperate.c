#include"../MapOperating/mapOperate.h"
#include"../Buff/buff.h"
#include<time.h>
#include<math.h>

void roll(Player *PPrime, int maxRoll, unsigned int seedOffSet) {
    srand(time(NULL) - seedOffSet);
    unsigned int seed = (unsigned) rand();
    srand(seed);printf("%s memutuskan untuk ROLL\n", PLAYER(PPrime));
    int rollVal;
    if (PPrime->buff[3]) {
        rollVal = (rand() % (maxRoll + 1 - (int)floor(maxRoll/2))) + (int)floor(maxRoll/2);
    } else if (PPrime->buff[4]) {
        rollVal = (rand() % (int)floor(maxRoll/2)) + 1;
    } else {
        rollVal = (rand() % maxRoll) + 1;
    }
    printf("Roll value: %d\n", rollVal);
    if (PPrime->position + rollVal <= NbElmtChar(map) && GetElmtChar(map, PPrime->position + rollVal) != '#') {
        printf("%s dapat maju\n", PLAYER(PPrime));
        if (PPrime->position - rollVal >= 1 && GetElmtChar(map, PPrime->position - rollVal) != '#') {
            printf("%s dapat mundur\n", PLAYER(PPrime));
            int move = -999;
            while (move != 1 && move != 2) {
                printf("1. Maju ke %d\n2. Mundur ke %d\n", PPrime->position+rollVal, PPrime->position-rollVal);
                chooseMode(&move);
            }
            if (move == 1) {
                PPrime->position += rollVal;
                printf("%s maju ke %d\n", PLAYER(PPrime),  PPrime->position);
            } else if (move == 2) {
                PPrime->position -= rollVal;
                printf("%s mundur ke %d\n", PLAYER(PPrime),  PPrime->position);
            }
        } else {
            PPrime->position += rollVal;
            printf("%s maju ke %d\n", PLAYER(PPrime),  PPrime->position);
        }
        teleport(PPrime, tIn, tOut);
    } else {
        if (PPrime->position - rollVal >= 1 && GetElmtChar(map, PPrime->position - rollVal) != '#') {
            printf("%s dapat mundur\n", PLAYER(PPrime));
            PPrime->position -= rollVal;
            printf("%s mundur ke %d\n", PLAYER(PPrime),  PPrime->position);
            teleport(PPrime, tIn, tOut);
        } else {
            printf("%s tidak bisa bergerak ke mana-mana\n", PLAYER(PPrime));
        }
    }
    printf("Posisi %s sekarang ada di petak %d\n", PLAYER(PPrime), PPrime->position);
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

void teleport(Player *P, TabInt teleporterIn, TabInt teleporterOut) {
    IdxType i = GetIdx(teleporterIn, P->position);
    if (i != IdxUndef) {
        int teleportPos;
        if (!P->buff[1]) {
            teleportPos = GetElmt(teleporterOut, i);
            printf("Terjadi teleportasi ke %d\n", teleportPos);
            P->position = teleportPos;
        } else {
            teleportPos = GetElmt(teleporterOut, i);
            printf("Akan terjadi teleportasi menuju ke %d, tetap ikuti teleporter ini? (y/n)\n", teleportPos);
            char opt;
            printf("> ");
            scanf("%s", &opt);
            while (opt != 'y' && opt != 'n') {
                printf("INVALID!\n");
                printf("> ");
                scanf("%s", &opt);
            }
            if (opt == 'y') {
                teleportPos = GetElmt(teleporterOut, i);
                printf("Terjadi teleportasi ke %d\n", teleportPos);
                P->position = teleportPos;
            } else {
                printf("Tidak terjadi teleportasi, Imunitas Teleport digunakan\n");
                deactivateBuff(P, 1);
            }
        }
    } else {
        printf("Tidak terjadi teleportasi\n");
    }
}