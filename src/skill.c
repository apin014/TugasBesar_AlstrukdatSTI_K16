#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"
#include "player.h"
#include <string.h>
#include <time.h>

int RandomSkill(int number)
{
    if (number >= 1 && number <= 10)
    {
        printf("Pintu Ga Ke Mana Mana\n");
    }
    else if (number >= 11 && number <= 20)
    {
        printf("Mesin Waktu\n");
    }
    else if (number >= 21 && number <= 30)
    {
        printf("Baling Baling Jambu\n");
    }
    else if (number >= 31 && number <= 36)
    {
        printf("Cermin Pengganda\n");
    }
    else if (number >= 37 && number <= 51)
    {
        printf("Senter Pembesar Hoki\n");
    }
    else if (number >= 52 && number <= 66)
    {
        printf("Senter Pengecil Hoki\n");
    }
    else if (number >= 67 && number <= 70)
    {
        printf("Mesin Penukar Posisi\n");
    }
    else
    {
        printf("Teknologi Gagal\n");
    }
}

int main ()
{
    int input, number;
    List skill;
    Player P;
    printf ("Kamu memiliki skill :\n");
    InsVLast(&skill, RandomSkill(number)); /* Masih bingung kalau 2 skill nya */
    printf ("Tekan 0 untuk keluar. Masukkan bilangan negatif untuk membuang skill.\n");
    printf("Masukkan skill: ");
    scanf("%d", &input);
    if (input > 0)
    {
        UseSkill(P, input);
        DelP(&skill, input);

    }
    else if (input < 0)
    {
        input = input * -1;
        RemoveSkill(&P, &input);
        DelP(&skill, input);
    }
    else
    {
        printf("Player keluar dari menu skill\n");
    }
}
