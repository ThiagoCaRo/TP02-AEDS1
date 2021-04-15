#include "Menu.h"


void Manual(void){
    clock_t tempo;
    int C,N,i,j,k,op;
    printf("Entre com o numero de clausulas e posteriormente com o numero de variaveis booleanas no formato: CLAUSULAS VARIAVEIS\n");
    scanf("%d %d",&C,&N);
    int Expressao[C][N],MatrizVerdade[C][N];
    printf("Preencha a expressao:\n");
    for(i=0;i<C;i++){
        for(j=0;j<N;j++){
            printf("CLAUSULA %d: A variavel X%d existe?\n\n  QUALQUER INTEIRO -> SIM\n  2 -> NAO\n\n",i+1,j+1);
            scanf("%d",&op);
            if(op==2){
                Expressao[i][j]=0;
            }
            else{
                printf("A variavel X%d esta negada?\n\n  QUALQUER INTEIRO -> SIM\n  2 -> NAO\n\n",j+1);
                scanf("%d",&op);
                if(op==2){
                    Expressao[i][j]=2;
                }
                else{
                    Expressao[i][j]=1;
                }
            }
        }
    }
    tempo=clock();
    int sum,prod=1;
    char vet[40];
    for(i = 0; i < (pow(2,N)); i++) {
        prod=1;
        vet[0 ] = (i & 1       )?1:0;
        vet[1 ] = (i & 2       )?1:0;
        vet[2 ] = (i & 4       )?1:0;
        vet[3 ] = (i & 8       )?1:0;
        vet[4 ] = (i & 16      )?1:0;
        vet[5 ] = (i & 32      )?1:0;
        vet[6 ] = (i & 64      )?1:0;
        vet[7 ] = (i & 128     )?1:0;
        vet[8 ] = (i & 256     )?1:0;
        vet[9 ] = (i & 512     )?1:0;
        vet[10] = (i & 1024    )?1:0;
        vet[11] = (i & 2048    )?1:0;
        vet[12] = (i & 4096    )?1:0;
        vet[13] = (i & 8192    )?1:0;
        vet[14] = (i & 16384   )?1:0;
        vet[15] = (i & 32768   )?1:0;
        vet[16] = (i & 65536   )?1:0;
        vet[17] = (i & 131072  )?1:0;
        vet[18] = (i & 262144  )?1:0;
        vet[19] = (i & 524288  )?1:0;
        vet[20] = (i & 1048576 )?1:0;
        vet[21] = (i & 2097152 )?1:0;
        vet[22] = (i & 4194304 )?1:0;
        vet[23] = (i & 8388608 )?1:0;
        vet[24] = (i & 16777216)?1:0;
        vet[25] = (i & 33554432)?1:0;
        vet[26] = (i & 67108864)?1:0;
        vet[27] = (i & 134217728)?1:0;
        vet[28] = (i & 268435456)?1:0;
        vet[29] = (i & 536870912)?1:0;
        vet[30] = (i & 1073741824)?1:0;
        vet[31] = (i & 2147483648)?1:0;
        vet[32] = (i & 4294967296)?1:0;
        vet[33] = (i & 8589934592)?1:0;
        vet[34] = (i & 17179869184)?1:0;
        vet[35] = (i & 34359738368)?1:0;
        vet[36] = (i & 68719476736)?1:0;
        vet[37] = (i & 137438953472)?1:0;
        vet[38] = (i & 274877906944)?1:0;
        vet[39] = (i & 549755813888)?1:0;
        vet[40] = (i & 1099511627776)?1:0;
        for(j=0;j<C;j++){
            sum=0;
            for(k=0;k<N;k++){
                //printf("%d  ",vet[k]);
                if(Expressao[j][k]!=0){
                    if(Expressao[j][k]==2){
                        MatrizVerdade[j][k]=vet[k];
                    }
                    else if(Expressao[j][k]==1){
                        if(vet[k]==1)MatrizVerdade[j][k]=0;
                        else MatrizVerdade[j][k]=1;
                    }
                }
                if(Expressao[j][k]==0)MatrizVerdade[j][k]=-1;
                //printf("%d ",MatrizVerdade[j][k]);
                if(MatrizVerdade[j][k]!=-1)sum+=MatrizVerdade[j][k];
            }
            //printf("Soma %d: %d\n",i,sum);
            prod*=sum;
            //printf("\n");
        }
        if(prod!=0){
            for(k=0;k<N;k++){
                printf("%d ",vet[k]);
            }

            printf("   --->   Satisfaz a equacao\n");
        }

    }


    getchar();
    printf("Tempo de execucao desconsiderando as entradas: %.4f s",(clock()-tempo)/(double)(CLOCKS_PER_SEC));
}

void Automatico(void){
    srand(time(NULL));
    clock_t tempo;
    int C,N,i,j,k,op;
    printf("Entre com o numero de variaveis booleanas: VARIAVEIS\n");
    scanf("%d",&N);
    C=(N/3)*2;
    int Expressao[C][N],MatrizVerdade[C][N],NUM;
    printf("Preencha a expressao:\n");
    for(i=0;i<C;i++){
        for(j=0;j<N;j++){
            Expressao[i][j]=0;
        }
    }
    for(i=0;i<C;i++){
        Expressao[i][rand()%N]=1+(rand()%2);
        Expressao[i][rand()%N]=1+(rand()%2);
        Expressao[i][rand()%N]=1+(rand()%2);
    }
    tempo=clock();
    int sum,prod=1;
    char vet[40];
    for(i = 0; i < (pow(2,N)); i++) {
        prod=1;
        vet[0 ] = (i & 1       )?1:0;
        vet[1 ] = (i & 2       )?1:0;
        vet[2 ] = (i & 4       )?1:0;
        vet[3 ] = (i & 8       )?1:0;
        vet[4 ] = (i & 16      )?1:0;
        vet[5 ] = (i & 32      )?1:0;
        vet[6 ] = (i & 64      )?1:0;
        vet[7 ] = (i & 128     )?1:0;
        vet[8 ] = (i & 256     )?1:0;
        vet[9 ] = (i & 512     )?1:0;
        vet[10] = (i & 1024    )?1:0;
        vet[11] = (i & 2048    )?1:0;
        vet[12] = (i & 4096    )?1:0;
        vet[13] = (i & 8192    )?1:0;
        vet[14] = (i & 16384   )?1:0;
        vet[15] = (i & 32768   )?1:0;
        vet[16] = (i & 65536   )?1:0;
        vet[17] = (i & 131072  )?1:0;
        vet[18] = (i & 262144  )?1:0;
        vet[19] = (i & 524288  )?1:0;
        vet[20] = (i & 1048576 )?1:0;
        vet[21] = (i & 2097152 )?1:0;
        vet[22] = (i & 4194304 )?1:0;
        vet[23] = (i & 8388608 )?1:0;
        vet[24] = (i & 16777216)?1:0;
        vet[25] = (i & 33554432)?1:0;
        vet[26] = (i & 67108864)?1:0;
        vet[27] = (i & 134217728)?1:0;
        vet[28] = (i & 268435456)?1:0;
        vet[29] = (i & 536870912)?1:0;
        vet[30] = (i & 1073741824)?1:0;
        vet[31] = (i & 2147483648)?1:0;
        vet[32] = (i & 4294967296)?1:0;
        vet[33] = (i & 8589934592)?1:0;
        vet[34] = (i & 17179869184)?1:0;
        vet[35] = (i & 34359738368)?1:0;
        vet[36] = (i & 68719476736)?1:0;
        vet[37] = (i & 137438953472)?1:0;
        vet[38] = (i & 274877906944)?1:0;
        vet[39] = (i & 549755813888)?1:0;
        vet[40] = (i & 1099511627776)?1:0;
        for(j=0;j<C;j++){
            sum=0;
            for(k=0;k<N;k++){
                //printf("%d  ",vet[k]);
                if(Expressao[j][k]!=0){
                    if(Expressao[j][k]==2){
                        MatrizVerdade[j][k]=vet[k];
                    }
                    else if(Expressao[j][k]==1){
                        if(vet[k]==1)MatrizVerdade[j][k]=0;
                        else MatrizVerdade[j][k]=1;
                    }
                }
                if(Expressao[j][k]==0)MatrizVerdade[j][k]=-1;
                //printf("%d ",MatrizVerdade[j][k]);
                if(MatrizVerdade[j][k]!=-1)sum+=MatrizVerdade[j][k];
            }
            //printf("Soma %d: %d\n",i,sum);
            prod*=sum;
            //printf("\n");
        }
        if(prod!=0){
            for(k=0;k<N;k++){
                printf("%d ",vet[k]);
            }

            printf("   --->   Satisfaz a equacao\n");
        }

    }


    getchar();
    printf("Tempo de execucao desconsiderando as entradas: %.4f s",(clock()-tempo)/(double)(CLOCKS_PER_SEC));
}
