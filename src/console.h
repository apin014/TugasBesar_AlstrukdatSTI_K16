#ifndef CONSOLE_H
#define CONSOLE_H

#include"ADT/boolean.h"
#include"ADT/player.h"
#include"ADT/arrayChar.h"
#include"ADT/array.h"
#include"ADT/state.h"

extern int gameStatus, maxRoll, teleporterCount;
extern TabChar map;
extern TabInt tIn, tOut;
extern Player p1, p2;
extern State sP1, sP2;

void menu();

void newGame();

void chooseMode(int *spec);

#endif