#include "Menu.h"
void tabela_verdade(int colunas);

int main(){
    int op;
    do{
        printf("\n\n\n***********************************************************\n");
        printf("*  Universidade Federal de Vicosa - Campus Florestal      *\n");
        printf("*  Primeiro Trabalho Pratico da Disciplina CCF211 2021/1  *\n");
        printf("*  Alunos: Guilherme Correa Souza - 3509                  *\n");
        printf("*          Thiago Candido         - 4225                  *\n");
        printf("*          Aroldo Augusto         - 4250                  *\n");
        printf("*********************************************************\n\n");

        printf("***********************************************************\n");
        printf("*                       USER GUIDE                    *\n");
        printf("***********************************************************\n");
        printf("* O programa aceita como entrada para o numero de variaveis apenas inteiros >= 3 *\n\n");
        printf("* Caso nada seja apresentado na saida, significa que nao existem valores booleanos para aquela equacao \n  (|E=[~X1]^[X1]| por exemplo) *\n\n");
        printf("***********************************************************\n");

        printf("***********************************************************\n");
        printf("*                    FORMA DE ENTRADA                     *\n");
        printf("***********************************************************\n");
        printf("* 1 - Manual                                         *\n");
        printf("* 2 - Automatica                                            *\n");
        printf("* 0 - System Exit                                         *\n");
        printf("***********************************************************\n");

        scanf("%d", &op);
        switch (op)
        {
        case 1:
            Manual();
            break;

        case 2:
            Automatico();
            break;

        case 0:
            break;
        }

    }while (op != 0);

    return 0;

}

