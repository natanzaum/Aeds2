#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "labirinto.h"

int main (int argc, char *argv[])

{
    if (argv[1]==NULL || argv[2]==NULL || argv[3]==NULL)
    {
        printf("Voce esqueceu de colocar o nome de algum dos arquivos e ou parametros! \n");
        printf("Tente novamente! \n\n");
        exit(1);
//Resolve o erro do programa fechar se faltar algum dos arquivos/parametros
    }

    Labirinto *lab;
    int **sol;

    switch(atoi(argv[3]))
    {
    case 0: //Rotina da função recursiva
        lab = (LeLabirinto(argv[1]));
        sol = criaSolucao(lab);
        CaminhaLabirintoRecursivo(lab, lab->x, lab->y, sol);
        imprimeArquivo(lab, sol, argv[2]);
        liberaSol(lab, sol);
        liberaMapa(lab);
        break;

    case 1://Rotina da função iterativa
        lab = (LeLabirinto(argv[1]));
        sol = criaSolucao(lab);
        CaminhaLabirintoIterativo(lab, sol);
        imprimeArquivo(lab, sol, argv[2]);
        liberaSol(lab, sol);
        liberaMapa(lab);
        break;

    default:
        printf("\nVoce deve digitar 0 para o algoritmo recursivo ou 1 para o algoritimo iterativo\n");
    }

    return 0;
}
