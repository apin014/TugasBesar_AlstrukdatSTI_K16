#include"../ADT/player.h"
#include"../ADT/state.h"
#include"../ADT/boolean.h"
#include<stdio.h>
#include<stdlib.h>

#ifndef GAMEROUND_H
#define GAMEROUND_H

void commands1(Player *PPrime, Player *PSec, boolean *undoSignal);
/* Prosedur untuk menjalankan command yang player dapat gunakan pada turn nya */

void commands2(Player *PPrime, Player *PSec, boolean *undoSignal);
/* Prosedur untuk menjalankan command setelah dilakukan roll */

void play(State *SP1, State *SP2, Player *P1, Player *P2);
/* Prosedur untuk memainkan satu game penuh */

void playerTurn(Player *PPrime, Player *PSec, boolean *undoSignal);
/* Prosedur untuk menjalankan satu turn seorang pemain */

void undo(State *SP1, State *SP2, Player *P1, Player *P2);
/* Prosedur untuk mengembalikan state permainan ke state akhir ronde sebelumnya (sebelum ronde saat ini dimulai) */

#endif