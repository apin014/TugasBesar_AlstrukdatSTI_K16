#include<stdio.h>
#include<stdlib.h>
#include"ADT/mesin_kar.h"
#include"ADT/mesin_kata.h"
#include"ADT/array.h"
#include"ADT/arrayChar.h"
#include"ADT/boolean.h"

#ifndef READCONFIG_H
#define READCONFIG_H

void readConfig(char *filepath, TabChar *map, int *maxRoll, int *TeleporterCount, TabInt *TeleportIn, TabInt *TeleportOut);
/*
Membaca file konfigurasi dengan format .txt untuk digunakan dalam setup game Mobitangga
*/

#endif