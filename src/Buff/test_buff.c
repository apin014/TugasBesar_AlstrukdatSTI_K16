#include "buff.h"
#include "../ADT/mesin_kar.h"
#include "../ADT/mesin_kata.h"
#include <stdio.h>
#include <stdlib.h>

int main () {
    Player P;
    NewPlayer(&P);
    printf("Masukkan nama player: ");
    STARTNAME();
    KataToString(CKata, P.name);
    printf("<Player tidak memiliki buff apapun yang aktif>\n");
    BUFF(P);
    BuffImunitasTeleport(&P);
    printf("<Setelah aktivasi buff Imunitas Teleport>\n");
    BUFF(P);
    BuffSenterPembesarHoki(&P);
    printf("<Setelah aktivasi buff Senter Pembesar Hoki>\n");
    BUFF(P);
    deactivateBuff(&P, 3);
    BuffCerminPengganda(&P);
    printf("<Setelah deaktivasi buff Senter Pembesar Hoki dan aktivasi buff Cermin Pengganda>\n");
    BUFF(P);
    for (int i = 1; i <= 4; i++)
    {
        deactivateBuff(&P, i);
    }
    printf("<Setelah deaktivasi semua buff>\n");
    BUFF(P);

    printf("Insert (x/X) to continue\n");
    char c = getchar();
    while (c != 88 && c != 120)
    {
        c = getchar();
    }

    return 0;
}