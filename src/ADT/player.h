/* File : player.h */
/* contoh ADT Player berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */


#ifndef player_H
#define player_H

#include "boolean.h"
#include "listlinier.h"
#include <stdlib.h>

typedef struct {
    char name [255];
    int position;
    List skill ;
    List buff ;
}Player;

void NewPlayer(Player *P);
/* Menginisiasi player kosong yang baru */

char* PLAYER(Player *P);
/* Mengirim nama pemain */

void SKILL(Player P, int input);
/* Menampilkan daftar skill yang dimiliki dan menanyakan 
apakah pemain ingin menggunakan suatu skill. */

void UseSkill(Player P, int *input);
/* Menggunakan skill pemain jika memasukkan nilai positif */

void RemoveSkill(Player *P, int *input);
/* Membuang skill pemain jika memasukkan nilai negatif */

char SearchValue(List L, int X);
/* Mencari value dari suatu array dengan indeksnya */

void BUFF(Player P);
/* Menghasilkan daftar buff yang dimiliki pemain. */

#endif