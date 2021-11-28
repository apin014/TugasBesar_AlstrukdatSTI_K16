#include "buff.h"

void BuffImunitasTeleport (Player *P){
	P->buff[1] = true;
}

void BuffCerminPengganda (Player *P){
	P->buff[2] = true;
}

void BuffSenterPembesarHoki (Player *P){
    P->buff[3] = true;
}

void BuffSenterPengecilHoki (Player *P){
    P->buff[4] = true;
}

void BUFF (Player P){
	printf("%s memiliki buff aktif : \n", PLAYER(&P));
	for (int i = 1; i < 5; i++){
		if (P.buff[i]){
			printf("- %s\n", buffNames[i]);
		}
	}
}

void deactivateBuff (Player *P, int idx) {
	P->buff[idx] = false;
}