#include<stdio.h>
#include<stdlib.h>
#include"ADT/boolean.h"
#include"ADT/listlinier.h"
#include"ADT/player.h"


#ifndef skill_h
#define skill_h

char skillNames[8][32] = {
                            "Teknologi Gagal",
                            "Pintu Ga Ke Mana-Mana",
                            "Cermin Pengganda",
                            "Senter Pembesar Hoki",
                            "Senter Pengecil Hoki",
                            "Mesin Penukar Posisi",
                            "Mesin Waktu",
                            "Baling Baling Jambu"
                        };

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

int RandomSkill(int number);
/* randomized skill dalam representasi angka */

void SkillPintuGaKeManaMana (Player *P);

void SkillCerminPengganda (Player *P);
/* Gunakan skill ini dan mendapatkan dua buah skill baru. */

void SkillSenterPembesarHoki (Player *P);
/* Dadu akan menghasilkan angka antara floor(MaxRoll/2) dan MaxRoll. */

void SkillSenterPengecilHoki (Player *P);
/* Dadu akan menghasilkan angka antara 1 dan floor(MaxRoll/2). */

void SkillMesinPenukarPosisi (Player *P1, Player *P2);
/* Menukar posisi dengan pemain lain. */

void SkillMesinWaktu (Player *P2);

void SkillBalingBalingJambu (Player *P2);

void AddSkill(Player *P, int offSet);

void SKILL(Player *P1, Player *P2);
/* Menampilkan daftar skill yang dimiliki dan menanyakan apakah pemain ingin menggunakan suatu skill. */

void UseSkill1(Player *P, int input);
/* Menggunakan skill pemain jika memasukkan nilai positif */

void UseSkill2(Player *P1, Player *P2, int input);
/* Fungsi UseSkill yang melibatkan dua orang player */

void RemoveSkill(Player *P, int input);
/* Membuang skill pemain jika memasukkan nilai negatif */

int SearchValue(List L, int X);
/* Mencari value dari suatu array dengan indeksnya */

void PrintSkill (Player P);
/* Menampilkan skill player */

#endif
