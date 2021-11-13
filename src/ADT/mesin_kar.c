/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include"mesin_kar.h"
#include<stdio.h>
#include<stdlib.h>

char CC;
boolean EOP;

static FILE * pita;
static int retval;

void START() {
    pita = stdin;
    ADV();
}

void STARTFILE (const char *filename) {
    pita = fopen(filename, "r");
    if (pita != NULL) {
        ADV();
    }
}

void ADV() {
    retval = fscanf(pita,"%c",&CC);
    EOP = (CC == MARK);
    if (EOP) {
       fclose(pita);
    }
}