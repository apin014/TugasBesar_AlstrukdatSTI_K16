#include<stdio.h>
#include"ADT/mesin_kar.h"
#include"ADT/mesin_kata.h"
#include"ADT/array.h"
#include"console.h"

int main () {
    char filepath[255];
    char map[100];
    int maxroll, mapSize, TeleporterCount;
    TabInt TIn, TOut;
    MakeEmpty(&TIn); MakeEmpty(&TOut);
    printf("Masukkan path file konfigurasi: ");
    STARTKATA();
    KataToString(CKata, filepath);
    readConfig(filepath, &mapSize, map, &maxroll, &TeleporterCount, &TIn, &TOut);
    printf("Mapsize: %d\n", mapSize);
    printf("Map: \n");
    for (int i = 0; i < mapSize; i++)
    {
        printf("%c", map[i]);
    }
    printf("\n");
    printf("Max roll: %d\n", maxroll);
    printf("Teleporter count: %d\n", TeleporterCount);
    printf("Pintu masuk teleporter: \n");
    printf("[");
    for (int i = 1; i <= NbElmt(TIn); i++)
    {
        printf(" %d ", GetElmt(TIn, i));
    }
    printf("]\n");
    printf("Pintu keluar teleporter: \n");
    printf("[");
    for (int i = 1; i <= NbElmt(TOut); i++)
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