#include <stdio.h>
#include <stdlib.h>
#include "skill.h"
#include "listlinier.h"
#include "player.h"
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
    printf("%c memakai skill Cermin Pengganda\n", P->name);
    if (NbElmt(P->skill) < 10){
        AddSkill(P);
        AddSkill(P);
        P->buff[2] = 0;
        }
    }
}

void SkillSenterPembesarHoki (Player *P){
    if (!P->buff[3]) {
        printf ("Anda tidak dapat menggunakan skill Cermin Pengganda.");
    }
    else {
        printf("%c memakai skill Senter Pembesar Hoki\n", *P->name);
        roll(2);
        P->buff[3] = 0;
    }
}

void SkillSenterPengecilHoki (Player *P){
    if (!P->buff[4]) {
        printf ("Anda tidak dapat menggunakan skill Cermin Pengganda.");
    }
    else {
        printf("%c memakai skill Senter Pengecil Hoki\n", *P->name);
        roll(1);
        P->buff[4] = 0;
    }    
}

void SkillMesinPenukarPosisi (Player *P1, Player *P2){
    int idxpemain ;
    List temp;
    CreateEmptyList(&temp);
    printf("%c memakai skill Senter Pembesar Hoki\n", *P1->name);
    printf ("Pilih pemain yang ingin ditukar posisi :\n");
    printf("2. %c" , *P2->name);
    printf(" ");
    scanf("Masukkan pemain: %d\n", &idxpemain);
    First(temp) = &P1->position;
    P1->position = &P2->position;
    P2->position = info(First(temp));

    printf ("%c sekarang berada di petak %d. ", *P1->name, &P1->position); 
    printf ("%c sekarang berada di petak %d. ", *P2->name, &P2->position); 
    //fungsi tidak memicu teleporter
}

void AddSkill(Player *P)
{
    address loc = First(P->skill);
    int x ;
    
    if (loc != Nil)
    {
        if (NbElmt(P->skill) < 10){
            x = RandomSkill((rand() % 100) + 1);
            if (x != 0){
                InsVLast(&P->skill, x);
            }
            else {
                printf ("Teknologi Gagal.");
            }
        } else
        {
            printf("Skill sudah penuh.\n");
        }
    }
}

void SKILL(Player P)
{
    int idx = 1;
    int input;
    AddSkill(&P);
    printf ("Kamu memiliki skill :\n");
    PrintSkill(P);
    printf("Tekan 0 untuk keluar. Masukkan bilangan negatif untuk membuang skill.\n");
    scanf("Masukkan skill: %d \n", input);
    if (input > 0){
        UseSkill(P, input);
        DelP(&P, input);
    }
    else if (input < 0){
        RemoveSkill(&P, input);
    }
    else {
        exit;
    }
}

void UseSkill(Player P, int input)
{
    if (SearchValue(P.skill, input) == 1) 
    {
        printf("%c memakai skill Pintu Ga Ke  Mana Mana\n", P.name);
        //Run Skill Function
    }
    else if (SearchValue(P.skill, input) == 2) 
    {
        printf("%c memakai skill Cermin Pengganda\n", P.name);
        SkillCerminPengganda(&P);
    }
    else if (SearchValue(P.skill, input) == 3) 
    {
        printf("%c memakai skill Senter Pembesar Hoki\n", P.name);
        SkillSenterPembesarHoki(&P);
    }
    else if (SearchValue(P.skill, input) == 4) 
    {
        printf("%c memakai skill Senter Pengecil Hoki\n", P.name);
        SkillSenterPengecilHoki(&P);
    }
    else if (SearchValue(P.skill, input) == 4)  
    {
        Player P1;
        Player P2;
        printf("%c memakai skill Mesin Penukar Posisi\n", P1.name);
        SkillMesinPenukarPosisi(&P1, &P2);  
    }
    else if (SearchValue(P.skill, input) == 2 )  
    {
        printf("%c memakai skill Mesin Waktu\n", P.name);
        //Run Skill Function
    }
    else if (strcmp(SearchValue(P.skill, input), "Baling Baling Jambu") == 0 ) 
    {
        printf("%c memakai skill Baling Baling Jambu\n", P.name);
        //Run Skill Function
    }
}

void RemoveSkill(Player *P, int input)
{
    int input = input * (-1);
    DelP(&P->skill, SearchValue(P->skill, input));
}

int SearchValue(List L, int X)
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


void PrintSkill (Player P){
    int idx;
    if (IsListEmpty(P.skill)){
        printf(" ");
    }
    else {
        address loc;
        loc = First(P.skill);
        while (loc != Nil){
            printf ("%d. ",idx);
            printf ("%c\n", skillNames[Info(loc)]);
            loc = Next(loc);
            idx ++;
        }
}

// char ConvertSkill (int x){
//     if (x == 1) {
//         return "Pintu Ga Ke Mana Mana";
//     }
//     else if (x == 2) {
//         return "Cermin Pengganda";
//     }
//     else if (x == 3){
//         return "Senter Pembesar Hoki"
//     }
//     else if (x == 4) {
//         return "Senter Pengecil Hoki";
//     }
//     else if (x == 5){
//         return "Mesin Penukar Posisi";
//     }
//     else if (x == 6){
//         return "Mesin Waktu";
//     }
//     else if (x == 7){
//         return "Baling Baling Jambu";
//     }
//     else if (x == 7){
//         return "Baling Baling Jambu";
//     }

// }