/* ADT STATE

Menggunakan konsep stack untuk menyimpan kondisi permainan */

#include <stdio.h>
#include "boolean.h"
#include "state.h"
#include "player.h"

void CreateEmpty (State *S)
{
    Top(*S) = Nil;
}

boolean IsEmpty (State S)
{
    return (Top(S) == Nil);
}

boolean IsFull (State S)
{
    return (Top(S) == MaxTurn);
}

void PushPlayer (State * S, Player X)
{
    Top(*S)++;
    InfoTop(*S) = X;
}

void PopPlayer (State * S, Player* X)
{
    *X = InfoTop(*S);
    Top(*S)--;
}