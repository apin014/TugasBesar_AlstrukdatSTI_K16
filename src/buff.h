#ifndef buff_H
#define buff_H

#include "ADT/boolean.h"

const char *buffNames[5];
buffNames[1] = "Imunitas Teleport";
buffNames[2] = "Cermin Pengganda";
buffNames[3] = "Senter Pembesar Hoki";
buffNames[4] = "Senter Pengecil Hoki";

typedef struct {
    char name [255];
    int position;
    List skill ;
    boolean buff[5] = {false, false, false, false, false};
}Player;

void imunitas_teleport(Player *P);
/* Mengaktifkan buff Imunitas Teleport */

void cermin_pengganda(Player *P);
/* Mengaktifkan buff Cermin Pengganda */

void senter_pembesar_hoki(Player *P);
/* Mengaktifkan buff Senter Pembesar Hoki */

void senter_pengecil_hoki(Player *P);
/* Mengaktifkan buff Senter Pengecil Hoki */

void printBuff(Player P);
/* Menampilkan semua buff aktif yang dimiliki player */

#endif