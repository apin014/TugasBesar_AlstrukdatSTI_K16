/* ADT STATE

Menggunakan konsep stack untuk menyimpan kondisi permainan */

#include "state.h"


void CreateEmptyState (State *S)
{
    Top(*S) = NIL;
}

boolean IsStateEmpty (State S)
{
    return (Top(S) == NIL);
}

boolean IsStateFull (State S)
{
    return (Top(S) == MaxTurn);
}

void PushPlayer (State * S, Player X)
{
    if (!IsStateFull(*S)) {
        Top(*S)++;
        InfoTop(*S) = X;
    }
}

void PopPlayer (State * S, Player* X)
{
    if (!IsStateEmpty(*S)) {
        *X = InfoTop(*S);
        Top(*S)--;
    }
}