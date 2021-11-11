#include"mesin_kata.h"
#include<stdio.h>

boolean EndKata;
Kata CKata;

void IgnoreBlank () {
    while (CC == BLANK || CC == NEWLINE)
    {
        ADV();
    }
}

void SalinKata () {
    int i = 1;
    while (((CC != MARK) && (CC != BLANK)) && (CC != NEWLINE))
    {
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    }
    CKata.Length = i - 1;
}

void STARTKATA (const char *filename) {
    START(filename);
    IgnoreBlank();
    if (CC == MARK) {
        EndKata = true;
    } else {
        EndKata = false;
        SalinKata();
    }
}

void ADVKATA () {
    IgnoreBlank();
    if (CC == MARK) {
        EndKata = true;
    } else {
        SalinKata();
    }
}