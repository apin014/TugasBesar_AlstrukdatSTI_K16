/* File: mesinkar.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "boolean.h"

#define MARK '/'
/* State Mesin */
extern char CC;
extern boolean EOP;

void START(const char *filename);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Mengambil parameter nama file yang hendak dibaca */

void ADV();
/* Pita dimajukan satu karakter */

#endif