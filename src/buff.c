#include "buff.h"
#include "ADT/player.h"

/* Kemungkinan di sini bakal banyak berubah, tapi harusnya implementasinya ga susah nantinya.
jadi, aktivasi/dekativasi buff itu tinggal ubah array buff yang dimiliki player, yang asalnya false jadi true
atau kebalikannya.
*/
void BuffImunitasTeleport (Player P){
	P.buff[1] = true;
}

void BuffImunitasTeleport (Player P){
	P.buff[2] = true;
}

void BuffSenterPembesarHoki (Player P){
    P.buff[3] = true;
}

void BuffSenterPengecilHoki (Player P){
    P.buff[4] = true;
}

void BUFF(Player P){
	int i;
	printf("%c memiliki buff aktif : \n", P.name);
	for (i = 1; i < 5; i++){
		if (P.buff[i]){
			printf("- %s\n", buffNames[i]);
		}
	}
}































