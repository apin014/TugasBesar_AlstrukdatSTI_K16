#include"ADT/player.h"
#include"ADT/boolean.h"
#include<stdio.h>
#include<stdlib.h>

#ifndef GAMEROUND_H
#define GAMEROUND_H

void commands(Player *P);
/* Prosedur untuk menjalankan command yang player dapat gunakan pada turn nya */

void playRound();
/* Prosedur untuk memainkan satu round penuh sesuai dengan jumlah turn */

#endif