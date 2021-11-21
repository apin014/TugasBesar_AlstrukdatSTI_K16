#ifndef CONSOLE_H
#define CONSOLE_H

#include"ADT/boolean.h"
#include"ADT/mesin_kar.h"
#include"ADT/mesin_kata.h"
#include"ADT/array.h"
#include"ADT/arrayChar.h"
#include"ADT/listlinier.h"
#include"ADT/player.h"

int gameStatus, maxRoll, teleporterCount;
TabChar map;
TabInt tIn, tOut;
boolean gameFinished;
Player p1, p2;


void readConfig(const char *filepath, TabChar *map, int *maxRoll, int *TeleporterCount, TabInt *TeleportIn, TabInt *TeleportOut);
/*
Membaca file konfigurasi dengan format .txt untuk digunakan dalam setup game Mobitangga
*/

void menu();

void newGame();

void chooseMode(int *spec);

int roll(int buffStat, int maxRoll, unsigned int seedOffSet);

void printMap(TabChar map, int playerPosition);

void inspectTile(int tile, TabInt teleporterIn, TabInt teleporterOut);

void commands(Player *P);

void playRound();

#endif