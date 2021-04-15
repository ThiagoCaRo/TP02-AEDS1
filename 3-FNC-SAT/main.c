#include "Menu.h"

int main(){
    int op;
    printf("Escolha o modo de operacao:\n\n   QUALQUER INTEIRO -> Automatico\n   2-> Manual\n");
    scanf("%d",&op);
    if(op==2){
        Manual();
    }
    else{
        Automatico();
    }

    return 0;
}

