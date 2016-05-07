#include <stdio.h>
#include <stdlib.h>
#include "corcruzada.h"


PGM *LePGM(char* entrada)
{
    int i,j;

    FILE *arquivo;
    arquivo = fopen(entrada,"r");
    if(arquivo==NULL)
    {
        printf("O arquivo nao existe!!!\n\n\n");
        return 0;
    }

    PGM *cena = (PGM*) malloc(sizeof(PGM));
    if(cena!=NULL)
    {
        fscanf(arquivo,"%s", &cena->c);//Pula linha P2
        fscanf(arquivo,"%d %d %d", &cena->c, &cena->l, &cena->maximo);

        cena->dados = (unsigned char**) malloc(cena->l*sizeof(unsigned char*));
        for (i=0; i<cena->l; i++)
        {
            cena->dados[i]=(unsigned char*) malloc(cena->c*sizeof(unsigned char));
        }

        for (i=0; i<cena->l; i++)
            for(j=0; j<cena->c; j++)
            {
                // Por algum motivo, se fizer a atribuição direta, da erro na hora de desalocar o malloc usando o free.
                // Segundo o debug do codeblocks, ocorre um erro de segmentation fault.
                int a;
                fscanf(arquivo,"%d", &a);
                cena->dados[i][j] = a;
            }

        fclose(arquivo);

        return cena;
    }
}

int CorrelacaoCruzada(PGM *cena, PGM *obj, Ponto p)
{
    int i,j,somamulti;
    somamulti = 0;
    i=0;
    j=0;

    for(i=0; i<obj->l; i++)
    {
        for (j=0; j<obj->c; j++)
        {
            somamulti+=obj->dados[i][j]*cena->dados[i+p.y][j+p.x];
        }
    }

    return somamulti;

}

Ponto JanelaDeslizante(PGM *cena, PGM *obj)
{
    int i,j;
    int aux2;
    int aux = 0;

    Ponto p;
    Ponto q;

    for(i=0; i<=cena->l - obj->l; i++)
    {
        aux2 = 0;
        for (j=0; j<=cena->c - obj->c; j++)
        {
            p.x = j;
            p.y = i;

            aux2= CorrelacaoCruzada(cena, obj, p);

            if(aux<aux2)
            {
                aux = aux2;
                q.y = p.y;
                q.x = p.x;
            }
        }
    }

    return q;
}

void grava_pontos(Ponto p, char* entrada)
{
    FILE* arquivo;
    arquivo = fopen(entrada, "w");
    fprintf(arquivo,"%d %d", p.x, p.y);

    fclose(arquivo);

}

void libera_pgm(PGM *cena)
{
    int i;

    for(i=0; i<cena->l; i++)
    {
        free(cena->dados[i]);
    }
    free(cena);
}
