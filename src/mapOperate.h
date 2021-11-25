#include<stdlib.h>
#include<stdio.h>
#include"ADT/boolean.h"
#include"ADT/arrayChar.h"
#include"ADT/array.h"

#ifndef MAPOPERATE_H
#define MAPOPERATE_H

int roll(int buffStat, int maxRoll, unsigned int seedOffSet);
/* Fungsi untuk melakukan roll dan bergerak dari satu posisi ke posisi lain */

void printMap(TabChar map, int playerPosition);
/* Salah satu prosedur command untuk menampilkan posisi pemain */

void inspectTile(int tile, TabInt teleporterIn, TabInt teleporterOut);
/* Prosedur command untuk memeriksa apakah petak tertentu memiliki teleporter */

void teleport(int *position, TabInt teleporterIn, TabInt teleporterOut);
/* Prosedur untuk melakukan teleportasi */

#endif