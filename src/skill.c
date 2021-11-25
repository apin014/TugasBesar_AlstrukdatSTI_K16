#include <stdio.h>
#include <stdlib.h>
#include "skill.h"
#include <string.h>
#include <time.h>

/*
SKILL
1 : Pintu Ga Ke Mana Mana 
2 : Cermin Pengganda
3 : Senter Pembesar Hoki
4 : Senter Pengecil Hoki
5 : Mesin Penukar Posisi 
6 : Mesin Waktu
7 : Baling Baling Jambu 
0 : Teknologi Gagal

BUFF
1 : Imunitas Teleport
2 : Cermin Pengganda
3 : Senter Pembesar Hoki
4 : Senter Pengecil Hoki
*/

int RandomSkill(int number)
//randomizer untuk skill
{
    if (number >= 1 && number <= 10)
    {
        return 1;
    }
    else if (number >= 11 && number <= 20)
    {
        return 6;
    }
    else if (number >= 21 && number <= 30)
    {
        return 7;
    }
    else if (number >= 31 && number <= 36)
    {
        return 2;
    }
    else if (number >= 37 && number <= 51)
    {
        return 3;
    }
    else if (number >= 52 && number <= 66)
    {
        return 4;
    }
    else if (number >= 67 && number <= 70)
    {
        return 5;
    }
    else
    {
        return 0;
    }
}


void SkillCerminPengganda (Player *P){
    if (P->buff[2]) {
        printf ("Anda tidak dapat menggunakan skill Cermin Pengganda.");
    }
    else {
    printf("%c memakai skill Cermin Pengganda\n", PLAYER(P));
    if (NbElmt(P->skill) < 10){
        AddSkill(P);
        AddSkill(P);
        P->buff[2] = true;
        }
    }
}

void SkillSenterPembesarHoki (Player *P){
    if (P->buff[3] || P->buff[4]) {
        printf ("Anda tidak dapat menggunakan Senter Pembesar Hoki.");
    }
    else {
        printf("%c memakai skill Senter Pembesar Hoki\n", *P->name);
        P->buff[3] = true;
    }
}

void SkillSenterPengecilHoki (Player *P){
    if (P->buff[4] || P->buff[3]) {
        printf ("Anda tidak dapat menggunakan skill Senter Pengecil Hoki.");
    }
    else {
        printf("%c memakai skill Senter Pengecil Hoki\n", *P->name);
        P->buff[4] = true;
    }    
}

void SkillMesinPenukarPosisi (Player *P1, Player *P2){
    int t;
    printf("%c memakai skill Mesin Penukar Posisi\n", *P1->name);
    printf("Posisi %c: %d -> %d\n", PLAYER(P1), P1->position, P2->position);
    printf("Posisi %c: %d -> %d\n", PLAYER(P2), P2->position, P1->position);
    t = P1->position;
    P1->position = P2->position;
    P2->position = t;
    //fungsi tidak memicu teleporter
}

void AddSkill(Player *P)
{
    int x ;
    if (NbElmt(P->skill) < 10){
        x = RandomSkill((rand() % 100) + 1);
        if (x != 0){
            printf("Didapat skill %s\n", skillNames[x]);
            InsVLast(&P->skill, x);
        }
        else {
            printf ("Teknologi Gagal.\n");
        }
    } else {
        printf("Skill sudah penuh.\n");
    }
}

void SKILL(Player P)
{
    int idx = 1;
    int input;
    printf ("Kamu memiliki skill :\n");
    PrintSkill(P);
    printf("Tekan 0 untuk keluar. Masukkan bilangan negatif untuk membuang skill\n");
    printf("> ");
    scanf("%d", &input);
    if (input > 0){
        UseSkill1(P, input);
        RemoveSkill(&P, input);
    }
    else if (input < 0){
        RemoveSkill(&P, input);
    }
    else {
        printf("");
    }
}

void UseSkill1(Player P, int input)
{
    if (SearchValue(P.skill, input) == 1) 
    {
        printf("%s memakai skill Pintu Ga Ke  Mana Mana\n", PLAYER(&P));
        //Run Skill Function
    }
    else if (SearchValue(P.skill, input) == 2) 
    {
        printf("%s memakai skill Cermin Pengganda\n", PLAYER(&P));
        SkillCerminPengganda(&P);
    }
    else if (SearchValue(P.skill, input) == 3) 
    {
        printf("%s memakai skill Senter Pembesar Hoki\n", PLAYER(&P));
        SkillSenterPembesarHoki(&P);
    }
    else if (SearchValue(P.skill, input) == 4) 
    {
        printf("%s memakai skill Senter Pengecil Hoki\n", PLAYER(&P));
        SkillSenterPengecilHoki(&P);
    }
}

void UseSkill2(Player P1, Player P2, int input) {
    if (SearchValue(P.skill, input) == 5)  
    {
        printf("%s memakai skill Mesin Penukar Posisi\n", PLAYER(&P1));
        SkillMesinPenukarPosisi(&P1, &P2);  
    }
    else if (SearchValue(P.skill, input) == 6)  
    {
        printf("%s memakai skill Mesin Waktu\n", PLAYER(&P1));
        //Run Skill Function
    }
    else if (SearchValue(P.skill, input) == 7) 
    {
        printf("%s memakai skill Baling Baling Jambu\n", PLAYER(&P1));
        //Run Skill Function
    }
}

void RemoveSkill(Player *P, int input)
{
    input = abs(input);
    DelP(&(P->skill), SearchValue(P->skill, input));
}

int SearchValue(List L, int X)
{
    address P;
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
        return Info(P);
    }
}

void PrintSkill (Player P){
    if (IsListEmpty(P.skill)){
        printf("Tidak memiliki skill\n");
    }
    else {
        int idx = 1;
        address loc;
        loc = First(P.skill);
        while (loc != Nil){
            printf ("%d. ",idx);
            printf ("%s\n", skillNames[Info(loc)]);
            loc = Next(loc);
            idx ++;
        }
    }
}