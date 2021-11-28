#include <stdlib.h>
#include <stdio.h>
#include"../ADT/boolean.h"
#include"../ADT/player.h"

#ifndef buff_H
#define buff_H

static char buffNames[5][32] = {
                            " ",
                            "Imunitas Teleport",
                            "Cermin Pengganda",
                            "Senter Pembesar Hoki",
                            "Senter Pengecil Hoki"
                        };
/* Daftar nama nama buff */

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