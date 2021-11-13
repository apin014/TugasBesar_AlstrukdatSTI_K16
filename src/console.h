#ifndef CONSOLE_H
#define CONSOLE_H

#include"ADT/boolean.h"
#include"ADT/mesin_kar.h"
#include"ADT/mesin_kata.h"
#include"ADT/array.h"
#include"ADT/arrayChar.h"

void readConfig(const char *filepath, TabChar *map, int *maxRoll, int *TeleporterCount, TabInt *TeleportIn, TabInt *TeleportOut);
/*
Membaca file konfigurasi dengan format .txt untuk digunakan dalam setup game Mobitangga
*/

#endif