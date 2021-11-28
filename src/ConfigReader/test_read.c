#include<stdio.h>
#include"../ADT/mesin_kar.h"
#include"../ADT/mesin_kata.h"
#include"../ADT/array.h"
#include"../ADT/arrayChar.h"
#include"readConfig.h"

int main () {
    char filepath[255];
    TabChar map;
    MakeEmptyChar(&map);
    int maxroll, TeleporterCount;
    TabInt TIn, TOut;
    MakeEmpty(&TIn); MakeEmpty(&TOut);
    printf("Masukkan path file konfigurasi: ");
    STARTNAME();
    KataToString(CKata, filepath);
    readConfig(filepath, &map, &maxroll, &TeleporterCount, &TIn, &TOut);
    printf("Mapsize: %d\n", NbElmtChar(map));
    printf("Map: \n");
    for (int i = 1; i <= NbElmtChar(map); i++)
    {
        printf("%c", GetElmtChar(map, i));
    }
    printf("\n");
    printf("Max roll: %d\n", maxroll);
    printf("Teleporter count: %d\n", TeleporterCount);
    printf("Pintu masuk teleporter: \n");
    printf("[");
    for (int i = 1; i <= NbEl(TIn); i++)
    {
        printf(" %d ", GetElmt(TIn, i));
    }
    printf("]\n");
    printf("Pintu keluar teleporter: \n");
    printf("[");
    for (int i = 1; i <= NbEl(TOut); i++)
    {
        printf(" %d ", GetElmt(TOut, i));
    }
    printf("]\n");
    printf("Insert (y/Y) to continue\n");
    char c = getchar();
    while (c != 89 && c != 121)
    {
        c = getchar();
    }
    
    
    return 0;
}