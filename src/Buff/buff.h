#ifndef buff_H
#define buff_H

#include"../ADT/boolean.h"
#include"../ADT/player.h"

char buffNames[5][32] = {
                            " ",
                            "Imunitas Teleport",
                            "Cermin Pengganda",
                            "Senter Pembesar Hoki",
                            "Senter Pengecil Hoki"
                        };

void BuffImunitasTeleport (Player *P);
/* Mengaktifkan buff Imunitas Teleport */

void BuffCerminPengganda (Player *P);
/* Mengaktifkan buff Cermin Pengganda */

void BuffSenterPembesarHoki (Player *P);
/* Mengaktifkan buff Senter Pembesar Hoki */

void BuffSenterPengecilHoki (Player *P);
/* Mengaktifkan buff Senter Pengecil Hoki */

void BUFF (Player P);
/* Menampilkan semua buff aktif yang dimiliki player */

void deactivateBuff (Player *P, int idx);
/* Deaktivasi buff */

#endif