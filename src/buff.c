#include "buff.h"
#include "ADT/player.h"

/* Kemungkinan di sini bakal banyak berubah, tapi harusnya implementasinya ga susah nantinya.
jadi, aktivasi/dekativasi buff itu tinggal ubah array buff yang dimiliki player, yang asalnya false jadi true
atau kebalikannya.
*/
void BUFF (Player *P){
	int idx = 1;
    printf ("Kamu memiliki buff :\n");
    if (IsListEmpty(P.buff)){
        printf(" ");
    }
    else {
        address loc;
        loc = First(P.buff);
        while (loc != Nil){
            printf ("%d. ",idx);
            printf ("%c\n", Info(loc));
            loc = Next(loc);
            idx ++;
        }
    }
}

void cek_imunitas_teleport(Player *P){
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
































