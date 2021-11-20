#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"
#include "listlinier.h"
#include "listlinier.c"
#include "player.h"




// void showskill (char *input){
//     char command[] = "SKILL";
//     if (strcmp(command, input) == 0) {
//         printf("Kamu memliki skill");
//     }
    
// }

// int main (){
//     char input;
//     scanf("%s", &input);
//     showskill(&input);
//     return 0;
// }

void PLAYER (Player P){
    printf("%c", Player.name)
}


void SKILL(Player P, int input){
    int idx = 1;
    printf ("Kamu memiliki skill :\n");
    if (IsEmpty(P.skill)){
        printf(" ");
    }
    else {
        address loc;
        loc = First(P.skill);
        while (loc != Nil){
            printf ("%d. ",idx);
            printf ("%c\n", Info(loc));
            loc = Next(loc);
            idx ++;
        }
    }
    printf ("Tekan 0 untuk keluar. Masukkan bilangan negatif untuk membuang skill.\n");
    scanf("Masukkan skill: %d", input);
    if (input > 0){
        UseSkill(P, input);
    }
    else {
        RemoveSkill(&P, &input);
    }
}


void UseSkill(Player P, int input){
    if (strcmp(SearchValue(P.skill, input), "Pintu Ga Ke  Mana Mana") == 0 ) {
        printf("%c memakai skill Pintu Ga Ke  Mana Mana\n", P.name);
        //Run Skill Function
    }
    else if (strcmp(SearchValue(P.skill, input), "Mesin Waktu") == 0 ) {
        printf("%c memakai skill Mesin Waktu\n", P.name);
        //Run Skill Function
    }
    else if (strcmp(SearchValue(P.skill, input), "Baling Baling Jambu") == 0 ) {
        printf("%c memakai skill Baling Baling Jambu\n", P.name);
        //Run Skill Function
    }
    else if (strcmp(SearchValue(P.skill, input), "Cermin Pengganda") == 0 ) {
        printf("%c memakai skill Cermin Pengganda\n", P.name);
         //Run Skill Function
    }
    else if (strcmp(SearchValue(P.skill, input), "Senter Pembesar Hoki") == 0 ) {
        printf("%c memakai skill Senter Pembesar Hoki\n", P.name);
        //Run Skill Function
    }
    else if (strcmp(SearchValue(P.skill, input), "Senter Pengecil Hoki") == 0 ) {
        printf("%c memakai skill Senter Pengecil Hoki\n", P.name);
        //Run Skill Function
    }
    else if (strcmp(SearchValue(P.skill, input), "Mesin Penukar Posisi") == 0 ) {
        printf("%c memakai skill Mesin Penukar Posisi\n", P.name);
        //Run Skill Function   
    }
    else if (strcmp(SearchValue(P.skill, input), "Teknologi Gagal") == 0 ) {
        printf("%c memakai skill Teknologi Gagal\n", P.name);
        //Run Skill Function
    }
}

void RemoveSkill (Player *P, int *input){
    DelP(&P.skill, &SearchValue(L, input));
}


char SearchValue (List L, int X){
    address P;
    List L;
    int idx = 1;
    P = First(L);
    if (!IsEmpty(L)){
        while (P!=Nil && idx!=X){
            if (idx == X){
                return Info(P);
                break;
            }
            else {
                P = Next(P);
                idx ++;
            }
        }
    }
}

void BUFF (Player P){
    int idx = 1;
    if (IsEmpty(P.buff)){
        printf(" ");
    }
    else {
        address loc;
        loc = First(P.buff);
        while (loc != Nil){
            printf ("%d. ",idx);
            printf ("%c\n", Info(loc));
            loc = Next(loc);
            idx ++;
        }
    }
}
