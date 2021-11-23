#include <stdio.h>
#include <stdlib.h>
#include "skill.h"
#include "listlinier.h"
#include "player.h"
#include <string.h>
#include <time.h>

void RandomSkill(int number)
{
    if (number >= 1 && number <= 10)
    {
        printf("%s\n", skillNames[0]);
    }
    else if (number >= 11 && number <= 20)
    {
        printf("%s\n", skillNames[1]);
    }
    else if (number >= 21 && number <= 30)
    {
        printf("%s\n", skillNames[2]);
    }
    else if (number >= 31 && number <= 36)
    {
        printf("%s\n", skillNames[3]);
    }
    else if (number >= 37 && number <= 51)
    {
        printf("%s\n", skillNames[4]);
    }
    else if (number >= 52 && number <= 66)
    {
        printf("%s\n", skillNames[5]);
    }
    else if (number >= 67 && number <= 70)
    {
        printf("%s\n", skillNames[6]);
    }
    else
    {
        printf("%s\n", skillNames[7]);
    }
}

void AddSkill(Player *P)
{
    address loc = First(L);
    srand(time(NULL));
    if (loc != Nil)
    {
        if (NbElmt(*P->skill) < 10){
            InsVLast(*P->skill,RandomSkill((rand() % 100) + 1))
        } else
        {
            printf("Skill sudah penuh\n")
        }
    }
}

void CerminPengganda (Player *P){
    printf("%s memakai skill Cermin Pengganda\n", P->name);
    if (NbElmt(*P->skill) < 10){
        AddSkill(*P);
        AddSkill(*P);
    }
}

void SenterPembesarHoki (Player *P){
    printf("%s memakai skill Senter Pembesasr Hoki\n", *P->name);
    //fungsi roll tapi antara floor(MaxRoll/2) dan MaxRoll
}

void SenterPembesarHoki (Player *P){
    printf("%s memakai skill Senter Pembesasr Hoki\n", *P->name);
    //fungsi roll tapi antara 1 dan floor(MaxRoll/2) 
}

void MesinPenukarPosisi (Player *P1, Player *P2){
    int idxpemain;
    List temp;
    CreateEmptyList(temp);
    printf("%s memakai skill Senter Pembesasr Hoki\n", *P1->name);
    printf ("Pilih pemain yang ingin ditukar posisi :\n");
    //tampil nama pemain lain
    scanf("%d", &idxpemain);
    First(temp) = P1->position;
    P1->position = P2->position;
    P2->position = info(First(temp)); 
}

void SKILL(Player P, int input)
{
    int idx = 1;
    AddSkill(&P);
    printf ("Kamu memiliki skill :\n");
    if (IsListEmpty(P.skill)){
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
    printf("Tekan 0 untuk keluar. Masukkan bilangan negatif untuk membuang skill.\n");
    scanf("Masukkan skill: %d \n", input);
    if (input > 0){
        UseSkill(P, input);
        DelP(&P, input);
    }
    else {
        RemoveSkill(&P, &input);
        DelP(&P, input);
    }
}

void UseSkill(Player P, int input)
{
    if (strcmp(SearchValue(P.skill, input), "Pintu Ga Ke  Mana Mana") == 0 ) 
    {
        printf("%c memakai skill Pintu Ga Ke  Mana Mana\n", P.name);
        //Run Skill Function
    }
    else if (strcmp(SearchValue(P.skill, input), "Mesin Waktu") == 0 ) 
    {
        printf("%c memakai skill Mesin Waktu\n", P.name);
        //Run Skill Function
    }
    else if (strcmp(SearchValue(P.skill, input), "Baling Baling Jambu") == 0 ) 
    {
        printf("%c memakai skill Baling Baling Jambu\n", P.name);
        //Run Skill Function
    }
    else if (strcmp(SearchValue(P.skill, input), "Cermin Pengganda") == 0 ) 
    {
        printf("%c memakai skill Cermin Pengganda\n", P.name);
         //Run Skill Function
    }
    else if (strcmp(SearchValue(P.skill, input), "Senter Pembesar Hoki") == 0 ) 
    {
        printf("%c memakai skill Senter Pembesar Hoki\n", P.name);
        //Run Skill Function
    }
    else if (strcmp(SearchValue(P.skill, input), "Senter Pengecil Hoki") == 0 ) 
    {
        printf("%c memakai skill Senter Pengecil Hoki\n", P.name);
        //Run Skill Function
    }
    else if (strcmp(SearchValue(P.skill, input), "Mesin Penukar Posisi") == 0 ) 
    {
        printf("%c memakai skill Mesin Penukar Posisi\n", P.name);
        //Run Skill Function   
    }
    else if (strcmp(SearchValue(P.skill, input), "Teknologi Gagal") == 0 ) 
    {
        printf("%c memakai skill Teknologi Gagal\n", P.name);
        //Run Skill Function
    }
}

void RemoveSkill(Player *P, int *input)
{
    DelP(&P.skill, &SearchValue(L, input));
}

char SearchValue(List L, int X)
{
    address P;
    List L;
    int idx = 1;
    P = First(L);
    if (!IsListEmpty(L)){
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
