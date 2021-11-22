#include<stdio.h>
#include<stdlib.h>
#include "boolean.h"
#include "listlinier.h"
#include "player.h"

#ifndef skill_h
#define skill_h

const char *skillNames[] = {"Pintu Ga Ke Mana Mana", "Mesin Waktu", 
"Baling Baling Jambu", "Cermin Pengganda",
"Senter Pembesar Hoki", "Senter Pengecil Hoki",
"Mesin Penukar Posisi","Teknologi Gagal"};

void RandomSkill(int number);
/* Menampilkan skill dari hasil random */

void TotalSkill(List *L, int X);
/* Mengecek jumlah skill pemain */

void SKILL(Player P, int input);
/* Menampilkan daftar skill yang dimiliki dan menanyakan 
apakah pemain ingin menggunakan suatu skill. */

void UseSkill(Player P, int *input);
/* Menggunakan skill pemain jika memasukkan nilai positif */

void RemoveSkill(Player *P, int *input);
/* Membuang skill pemain jika memasukkan nilai negatif */

char SearchValue(List L, int X);
/* Mencari value dari suatu array dengan indeksnya */

#endif
