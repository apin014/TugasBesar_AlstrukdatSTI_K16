#ifndef CONSOLE_H
#define CONSOLE_H

#include"ADT/boolean.h"
#include"ADT/mesin_kar.h"
#include"ADT/mesin_kata.h"
#include"ADT/array.h"

void readConfig(const char *filepath, int *mapSize, char *map, int *maxRoll, int *TeleporterCount, TabInt *TeleportIn, TabInt *TeleportOut);
/*
Membaca file konfigurasi dengan format .txt untuk digunakan dalam setup game Mobitangga
*/

void KataToString (Kata K, char *S);
/*
Konversi kata menjadi string
*/

#endif