#include "Menu.h"
void tabela_verdade(int colunas);

int main(){
    int op;
    printf("Escolha o modo de operacao:\n\n   QUALQUER INTEIRO -> Automatico\n   2-> Manual\n");
    scanf("%d",&op);
    if(op==2){
        Manual();
    }

    return 0;
}

