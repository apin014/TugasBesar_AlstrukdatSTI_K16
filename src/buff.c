#include "buff.h"
#include "ADT/player.h"

List activate_buffs(Player *P){
	int buff;
	List buff_aktif;
	address S;
	
	S = First(*P.buff);
	while (S != Nil){
		if (Info(S) == 1){
			imunitas_teleport(*P);
		}
		if (Info(S) == 2){
			cermin_pengganda(P);
		}
		if (Info(S) == 3){
			senter_pembesar_hoki(P);
		}
		if (Info(S) == 4){
			senter_pengecil_hoki(P);
		}
		S = Next(S);
	}
	
	return buff_aktif;
}

bool cek_imunitas_teleport(Player *P){
	List L; // List semua teleporter (gmn guys gangerti)
	bool teleport;
	char t;

	if (!Search(*P.buff, 1)){	// cari buff imun teleporter, kalau tidak punya dan player lagi di teleporter, gaada pilihan buat imune
		return true;
	}

	if (Search(L, *P.position)){	// punya buff imunitas, cek posisi kalo lagi di teleporter
		printf("Anda memiliki imunitas teleport, apakah anda ingin menggunakan teleport ini? (y/n) ");
		scanf("%c", &t);
		if (t == 'y'){
			teleport = true;    // tidak menggunakan buff
		} else {
			teleport = false;
		}
		DelP(P.buff, 1); // hapus buff
	} else {
		teleport = true;
	}

	return teleport;
}

void cermin_pengganda(Player *P){

}

void senter_pembesar_hoki(Player P, int roll){
    
}

void senter_pengecil_hoki(Player *P){
    
}
































