/* ADT STATE

Menggunakan konsep stack untuk menyimpan kondisi permainan */

#ifndef STATE_H
#define STATE_H

#include "boolean.h"
#include "player.h"
#include <stdlib.h>
#include <stdio.h>

#define NIL 0
#define MaxTurn 1024 /* Asumsi max turn 1000 */

/* Nil adalah state dengan elemen kosong atau tidak ada state yang disimpan. */
/* Karena indeks dalam bhs C dimulai 0 maka tabel dg indeks 0 tidak dipakai */

typedef int addressState; 

typedef struct {
  Player P[MaxTurn+1];
  addressState TOP; 
} State;

/* Selektor */
#define Top(S) (S).TOP
#define InfoTop(S) (S).P[(S).TOP]

void CreateEmptyState (State *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah state S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri state kosong : TOP bernilai Nil */

boolean IsStateEmpty (State S);
/* Mengirim true jika State kosong = Masih turn 1 */

boolean IsStateFull (State S);
/* Mengirim true jika tabel penampung kondisi State penuh = Jika ada max turn */

void PushPlayer (State * S, Player X);
/* Menambahkan X sebagai posisi player saat ini ke State S. */
/* I.S. S mungkin kosong, tabel penampung elemen State TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

void PopPlayer (State * S, Player* X);
/* Menghapus X dari State S (kembali ke state posisi player turn sebelumnya). */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

#endif