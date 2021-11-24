#include<stdio.h>
#include<stdlib.h>
#include "boolean.h"
#include "listlinier.h"
#include "player.h"


#ifndef skill_h
#define skill_h

const char *skillNames[8];
char skillNames[] = "Teknologi Gagal ";
char skillNames[] = "Pintu Ga Ke Mana Mana";
char skillNames[] = "Cermin Pengganda";
char skillNames[] = "Senter Pembesar Hoki";
char skillNames[] = "Senter Pengecil Hoki";
char skillNames[] = "Mesin Penukar Posisi";
char skillNames[] = "Mesin Waktu";
char skillNames[] = "Baling Baling Jambub";

/*
SKILL
1 : Pintu Ga Ke Mana Mana 
2 : Cermin Pengganda
3 : Senter Pembesar Hoki
4 : Senter Pengecil Hoki
5 : Mesin Penukar Posisi 
6 : Mesin Waktu
7 : Baling Baling Jambu 
0 : Teknologi Gagal

BUFF
1 : Imunitas Teleport
2 : Cermin Pengganda
3 : Senter Pembesar Hoki
4 : Senter Pengecil Hoki
*/

// const char *skillNames[] = {"Pintu Ga Ke Mana Mana", "Mesin Waktu", 
// "Baling Baling Jambu", "Cermin Pengganda",
// "Senter Pembesar Hoki", "Senter Pengecil Hoki",
// "Mesin Penukar Posisi","Teknologi Gagal"};

int RandomSkill(int number);
/* Menampilkan randomized skill dalam representasi angka */

// void SkillPintuGaKeManaMana (Player *P);
// /* Gunakan skill ini dan mendapatkan dua buah skill baru. */
// WIP

void SkillCerminPengganda (Player *P);
/* Gunakan skill ini dan mendapatkan dua buah skill baru. */

void SkillSenterPembesarHoki (Player *P);
/* Dadu akan menghasilkan angka antara floor(MaxRoll/2) dan MaxRoll. */

void SkillSenterPengecilHoki (Player *P);
/* Dadu akan menghasilkan angka antara 1 dan floor(MaxRoll/2). */

void SkillMesinPenukarPosisi (Player *P1, Player *P2);
/* Menukar posisi dengan pemain lain. */

void AddSkill(Player *P);

void SKILL(Player P);
/* Menampilkan daftar skill yang dimiliki dan menanyakan apakah pemain ingin menggunakan suatu skill. */

void UseSkill(Player P, int input);
/* Menggunakan skill pemain jika memasukkan nilai positif */

void RemoveSkill(Player *P, int input);
/* Membuang skill pemain jika memasukkan nilai negatif */

int SearchValue(List L, int X);
/* Mencari value dari suatu array dengan indeksnya */

void PrintSkill (Player P);
/* Menampilkan skill player */

// char ConvertSkill (int x);
// /* Mengubah representasi angka skill menjadi string */
// jadinya pake const char *


#endif
