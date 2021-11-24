#include "buff.h"
#include "ADT/player.h"

/* Kemungkinan di sini bakal banyak berubah, tapi harusnya implementasinya ga susah nantinya.
jadi, aktivasi/dekativasi buff itu tinggal ubah array buff yang dimiliki player, yang asalnya false jadi true
atau kebalikannya.
*/
void imunitas_teleport(Player *P){
	*P.buff[1] = true;
}

void cermin_pengganda(Player *P){
	*P.buff[2] = true;
}

void senter_pembesar_hoki(Player *P){
    *P.buff[3] = true;
}

void senter_pengecil_hoki(Player *P){
    *P.buff[4] = true;
}

void printBuff(Player P){
	int i;
	printf("Buff aktif : ")
	for (i = 1; i < 5; i++){
		if (P.buff[i]){
			printf("- %s\n", buffNames[i]);
		}
	}
}































