#include"console.h"
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>

int main() {
    int rollMax = 12;
    printf("Roll tanpa buff:");
    for (int i = 0; i < 10; i++)
    {
        printf(" %d ", roll(0, rollMax, i));
    }
    printf("\n");
    printf("Roll dengan buff senter pembesar hoki:");
    for (int i = 0; i < 10; i++)
    {
        printf(" %d ", roll(1, rollMax, i));
    }
    printf("\n");
    printf("Roll dengan buff senter pengecil hoki:");
    for (int i = 0; i < 10; i++)
    {
        printf(" %d ", roll(2, rollMax, i));
    }
    printf("\n");
    printf("Insert (y/Y) to continue\n");
    char c = getchar();
    while (c != 89 && c != 121)
    {
        c = getchar();
    }

    return 0;
}