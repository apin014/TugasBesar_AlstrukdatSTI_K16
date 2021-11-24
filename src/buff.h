#ifndef buff_H
#define buff_H

#include "boolean.h"

const char *buffNames[5];
char buffNames[] = " ";
char buffNames[] = "Imunitas Teleport";
char buffNames[] = "Cermin Pengganda";
char buffNames[] = "Senter Pembesar Hoki";
char buffNames[] = "Senter Pengecil Hoki";


typedef struct {
    char name [255];
    int position;
    List skill ;
    boolean buff[5];
}Player;

// Player buff[5]  = {false, false, false, false, false}; 
// udah ada di new player

void BuffImunitasTeleport (Player P);
/* Mengaktifkan buff Imunitas Teleport */

void BuffImunitasTeleport (Player P);
/* Mengaktifkan buff Cermin Pengganda */

void BuffSenterPembesarHoki (Player P);
/* Mengaktifkan buff Senter Pembesar Hoki */

void BuffSenterPengecilHoki (Player P);
/* Mengaktifkan buff Senter Pengecil Hoki */

void BUFF (Player P);
/* Menampilkan semua buff aktif yang dimiliki player */

#endif