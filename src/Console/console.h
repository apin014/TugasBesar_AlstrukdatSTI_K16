#ifndef CONSOLE_H
#define CONSOLE_H

#include"../ADT/boolean.h"
#include"../ADT/player.h"
#include"../ADT/arrayChar.h"
#include"../ADT/array.h"
#include"../ADT/state.h"

/* SPESIFIKASI GAME YANG SEDANG DIMAINKAN */
extern int gameStatus, maxRoll, teleporterCount;
extern TabChar map;
extern TabInt tIn, tOut;
extern Player p1, p2;
extern State sP1, sP2;

void menu();
/* Menampilkan menu utama (New Game dan Exit) */

void newGame();
/* Memulai game Mobitangga yang baru */

void chooseMode(int *spec);
/* Memilih mode dari menu yang ditampilkan pada menu utama */

#endif