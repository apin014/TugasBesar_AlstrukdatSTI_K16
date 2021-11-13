/* File: mesinkar.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "boolean.h"

#define MARK '/'
/* State Mesin */
extern char CC;
extern boolean EOP;

void START();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Mengambil parameter nama file yang hendak dibaca */

void STARTFILE(const char *filename);
/* Mesin membaca dari sebuah file
   alih-alih dari masukan keyboard */

void ADV();
/* Pita dimajukan satu karakter */

#endif