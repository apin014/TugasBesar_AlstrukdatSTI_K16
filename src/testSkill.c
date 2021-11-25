#include"skill.c"
#include"buff.c"
#include"buff.h"
#include"ADT/player.c"
#include"ADT/mesin_kar.c"
#include"ADT/mesin_kata.c"
#include"ADT/array.c"
#include"ADT/arrayChar.c"
#include"ADT/listlinier.c"
#include<stdio.h>

int main () {
    Player p1, p2;
    NewPlayer(&p1); NewPlayer(&p2);
    printf("p1 name: ");
    STARTKATA();
    KataToString(CKata, p1.name);
    printf("p2 name: ");
    STARTKATA();
    KataToString(CKata, p2.name);
    AddSkill(&p1);
    AddSkill(&p2);
    AddSkill(&p1);
    AddSkill(&p2);
    SKILL(&p1, &p2);
    // PrintSkill(p1);
    // printf("%d\n", Info(First(p1.skill)));
    PrintInfo(p1.skill);
    
    return 0;
}