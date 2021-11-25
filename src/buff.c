#include "buff.h"
#include "ADT/player.h"

void BuffImunitasTeleport (Player *P){
	P->buff[1] = true;
}

void BuffImunitasTeleport (Player *P){
	P->buff[2] = true;
}

void BuffSenterPembesarHoki (Player *P){
    P->buff[3] = true;
}

void BuffSenterPengecilHoki (Player *P){
    P->buff[4] = true;
}

void BUFF (Player P){
	int i;
	printf("%c memiliki buff aktif : \n", P.name);
	for (i = 1; i < 5; i++){
		if (P.buff[i]){
			printf("- %s\n", buffNames[i]);
		}
	}
}

void deactivateBuff (Player *P, int idx) {
	P->buff[idx] = false;
}