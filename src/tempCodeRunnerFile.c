

void SKILL(Player *P1, Player *P2)
{
    PrintSkill(*P1);
    if (!IsListEmpty(P1->skill)) {
        int input;
        printf("Tekan 0 untuk keluar. Masukkan bilangan negatif untuk membuang skill\n");
        printf(" ");
        scanf("Masukkan skill: %d", &input);
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