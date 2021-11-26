#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"
#include "listlinier.h"
#include "player.h"


void NewPlayer(Player *P) {
    P->position = 1;
    CreateEmptyList(&(P->skill));
    for (int i = 1; i <= 4; i++)
    {
        P->buff[i] = false;
    }
}

char* PLAYER(Player *P){
    return P->name;
}