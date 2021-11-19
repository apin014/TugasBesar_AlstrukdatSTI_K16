#include"listlinier.h"
#include<stdlib.h>
#include<stdio.h>

boolean IsEmpty (List L) {
    return (First(L) == Nil);
}

void CreateEmpty (List *L) {
    First(*L) = Nil;
}

address Alokasi (infotype X) {
    address p = (ElmtList*) malloc (sizeof(ElmtList));
    if(p != Nil) {
        Info(p) = X;
        Next(p) = Nil;
        return p;
    } else {
        return Nil;
    }
} 

void Dealokasi (address *P) {
    free(*P);
}

address Search (List L, infotype X) {
    address p = First(L);
    boolean found = false;
    while (p != Nil && !found) {
        if (Info(p) == X) {
            found = true;
        } else {
            p = Next(p);
        }
    }
    if (found) {
        return p;
    } else {
        return Nil;
    }
}

void InsertFirst (List *L, address P) {
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertLast (List *L, address P) {
    if (IsEmpty(*L)) {
        InsertFirst(L, P);
    } else {
        address last = First(*L);
        while (Next(last) != Nil) {
            last = Next(last);
        }
        Next(P) = Nil;
        Next(last) = P;
    }
}

void InsertAfter (List *L, address P, address Prec) {
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsVFirst (List *L, infotype X) {
    address p = Alokasi(X);
    if (p != Nil)
    {
        InsertFirst(L, p);
    }
}

void InsVLast (List *L, infotype X) {
    address p = Alokasi(X);
    if (p != Nil) 
    {
        InsertLast(L, p);
    }
}

void DelFirst (List *L, address *P) {
    *P = First(*L);
    First(*L) = Next(*P);
    Next(*P) = Nil;
}

void DelLast (List *L, address *P) {
    address p, loc;
    p = First(*L);
    loc = Nil;
    while (Next(p) != Nil) {
        loc = p;
        p = Next(p);
    }
    *P = p;
    if (loc == Nil) {
        First(*L) = Nil;
    } else {
        Next(loc) = Nil;
    }
}

void DelAfter (List *L, address *Pdel, address Prec) {
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = Nil;
}

void DelP (List *L, infotype X) {
    address p = Search(*L, X);
    if (p != Nil) {
        if (p == First(*L)) {
            DelFirst(L, &p);
        } else {
            address loc = First(*L);
            while (Next(loc) != p)
            {
                loc = Next(loc);
            }
            DelAfter(L, &p, loc);
        }
        Dealokasi(&p);
    }
}

void DelVFirst (List *L, infotype *X) {
    address p;
    DelFirst(L, &p);
    *X = Info(p);
    Dealokasi(&p);
}

void DelVLast (List *L, infotype *X) {
    address p;
    DelLast(L, &p);
    *X = Info(p);
    Dealokasi(&p);
}

void PrintInfo (List L) {
    if (IsEmpty(L)) {
        printf("[]");
    } else {
        address p = First(L);
        printf("[");
        while (Next(p) != Nil)
        {
            printf("%d,", Info(p));
            p = Next(p);
        }
        printf("%d]", Info(p));
    }
}

int NbElmt (List L) {
    int ctr = 0;
    address p = First(L);
    while (p != Nil)
    {
        ctr++;
        p = Next(p);
    }
    return ctr;
}

infotype Max (List L) {
    infotype maximum = Info(First(L));
    address p = Next(First(L));
    while (p != Nil)
    {
        if (Info(p) > maximum) {
            maximum = Info(p);
        }
        p = Next(p);
    }
    return maximum;
}

void Konkat1 (List *L1, List *L2, List *L3) {
    CreateEmpty(L3);
    if (IsEmpty(*L1)){
        First(*L3) = First(*L2);
    } else {
        First(*L3) = First(*L1);
        address lastL1 = First(*L1);
        while (Next(lastL1) != Nil){
            lastL1 = Next(lastL1);
        }
        Next(lastL1) = First(*L2);
    }
    CreateEmpty(L1);
    CreateEmpty(L2);
}

address AdrMax (List L) {
    return Search(L, Max(L));
}

infotype Min (List L) {
    infotype minimum = Info(First(L));
    address p = Next(First(L));
    while (p != Nil)
    {
        if (Info(p) < minimum) {
            minimum = Info(p);
        }
        p = Next(p);
    }
    return minimum;
}

address AdrMin (List L) {
    return Search(L, Min(L));
}

float Average (List L) {
    float sum = 0;
    int ctr = 0;
    address p = First(L);
    while (p != Nil)
    {
        sum += Info(p);
        ctr++;
        p = Next(p);
    }
    float avg = sum / ctr;
    return avg;
}

void InversList (List *L) {
    List L1;
    CreateEmpty(&L1);
    infotype X;
    while (!IsEmpty(*L)) {
        DelVFirst(L, &X);
        InsVFirst(&L1, X);
    }
    *L = L1;
}