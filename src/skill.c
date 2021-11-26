#include "skill.h"
#include <string.h>
#include <time.h>
#include "console.h"
#include "buff.h"

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

void SkillPintuGaKeManaMana (Player *P) {
    printf("%s memakai skill Pintu Ga Ke Mana Mana\n", PLAYER(P));
    BuffImunitasTeleport(P);
}

void SkillCerminPengganda (Player *P){
    if (P->buff[2] || NbElmt(P->skill) >= 10) {
        printf ("Tidak dapat menggunakan skill Cermin Pengganda\n");
    }
    else {
        printf("%s memakai skill Cermin Pengganda\n", PLAYER(P));
        AddSkill(P, time(NULL)/60);
        AddSkill(P, time(NULL)/3600);
        BuffCerminPengganda(P);
    }
}

void SkillSenterPembesarHoki (Player *P){
    if (P->buff[3] || P->buff[4]) {
        printf ("Tidak dapat menggunakan Senter Pembesar Hoki\n");
    }
    else {
        printf("%s memakai skill Senter Pembesar Hoki\n", PLAYER(P));
        BuffSenterPembesarHoki(P);
    }
}

void SkillSenterPengecilHoki (Player *P){
    if (P->buff[4] || P->buff[3]) {
        printf ("Tidak dapat menggunakan skill Senter Pengecil Hoki\n");
    }
    else {
        printf("%s memakai skill Senter Pengecil Hoki\n", PLAYER(P));
        BuffSenterPengecilHoki(P);
    }    
}

void SkillMesinPenukarPosisi (Player *P1, Player *P2){
    int t;
    printf("%s memakai skill Mesin Penukar Posisi\n", PLAYER(P1));
    printf("Posisi %S: %d -> %d\n", PLAYER(P1), P1->position, P2->position);
    printf("Posisi %S: %d -> %d\n", PLAYER(P2), P2->position, P1->position);
    t = P1->position;
    P1->position = P2->position;
    P2->position = t;
    //fungsi tidak memicu teleporter
}

void AddSkill(Player *P, int offSet)
{
    int x;
    srand(time(NULL) - offSet);
    if (NbElmt(P->skill) < 10){
        x = RandomSkill((rand() % 100) + 1);
        if (x != 0){
            printf("%s mendapat skill %s\n", PLAYER(P), skillNames[x]);
            InsVLast(&P->skill, x);
        }
        else {
            printf ("Teknologi Gagal\n");
        }
    } else {
        printf("Skill sudah penuh\n");
    }
}

void SKILL(Player *P1, Player *P2)
{
    PrintSkill(*P1);
    if (!IsListEmpty(P1->skill)) {
        int input;
        printf("Tekan 0 untuk keluar. Masukkan bilangan negatif untuk membuang skill\n");
        printf("> ");
        scanf("%d", &input);
        if (input > 0){
            if (SearchValue(P1->skill, input) != 5 && SearchValue(P1->skill, input) != 6 && SearchValue(P1->skill, input) != 7) {
                UseSkill1(P1, input);
            } else {
                UseSkill2(P1, P2, input);
            }
            RemoveSkill(P1, input);
        }
        else if (input < 0){
            RemoveSkill(P1, input);
        }
        else {
            printf("");
        }
    }
}

void UseSkill1(Player *P, int input)
{
    if (SearchValue(P->skill, input) == 1) 
    {
        SkillPintuGaKeManaMana(P);
    }
    else if (SearchValue(P->skill, input) == 2) 
    {
        SkillCerminPengganda(P);
    }
    else if (SearchValue(P->skill, input) == 3) 
    {
        SkillSenterPembesarHoki(P);
    }
    else if (SearchValue(P->skill, input) == 4) 
    {
        SkillSenterPengecilHoki(P);
    }
}

void UseSkill2(Player *P1, Player *P2, int input) {
    if (SearchValue(P1->skill, input) == 5)  
    {
        SkillMesinPenukarPosisi(P1, P2);  
    }
    else if (SearchValue(P1->skill, input) == 6)  
    {
        printf("%s memakai skill Mesin Waktu\n", PLAYER(P1));
        //Run Skill Function
    }
    else if (SearchValue(P1->skill, input) == 7) 
    {
        printf("%s memakai skill Baling Baling Jambu\n", PLAYER(P1));
        //Run Skill Function
    }
}

void RemoveSkill(Player *P, int input)
{
    infotype x;
    input = abs(input);
    address p;
    if (input == 1) {
        DelVFirst(&(P->skill), &x);
    } else {
        int idx = 1;
        p = First(P->skill);
        while (idx < input - 1) {
            idx++;
            p = Next(p);
        }
        address loc = Next(p);
        Next(p) = Next(loc);
        Dealokasi(&loc);
    }
}

int SearchValue(List L, int X)
{
    address P;
    int idx = 1;
    P = First(L);
    if (!IsListEmpty(L)){
        while (P!=Nil && idx!=X){
            P = Next(P);
            idx ++;
        }
        return Info(P);
    }
}

void PrintSkill (Player P){
    if (!IsListEmpty(P.skill)){
        printf ("Kamu memiliki skill :\n");
        int idx = 1;
        address loc;
        loc = First(P.skill);
        while (loc != Nil){
            printf ("%d. ",idx);
            printf ("%s\n", skillNames[Info(loc)]);
            loc = Next(loc);
            idx ++;
        }
    } else {
        printf("Tidak memiliki skill\n");
    }
}