/* File : player.h */
/* contoh ADT Player berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */


#ifndef player_H
#define player_H

#include "boolean.h"
#include "listlinier.h"
#include <stdlib.h>

typedef struct {
    char name [255];
    int position;
    List skill ;
    boolean buff [5] ;
}Player;



void NewPlayer(Player *P);
/* Menginisiasi player kosong yang baru */

char* PLAYER(Player *P);
/* Mengirim nama pemain */

#endif