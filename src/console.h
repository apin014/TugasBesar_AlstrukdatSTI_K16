#ifndef CONSOLE_H
#define CONSOLE_H

#include"ADT/boolean.h"
#include"ADT/player.h"
#include"ADT/arrayChar.h"
#include"ADT/array.h"

extern int gameStatus, maxRoll, teleporterCount;
extern TabChar map;
extern TabInt tIn, tOut;
extern boolean gameFinished;
extern Player p1, p2;

void menu();

void newGame();

void chooseMode(int *spec);

#endif