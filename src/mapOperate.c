#include"mapOperate.h"
#include<time.h>
#include<math.h>

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