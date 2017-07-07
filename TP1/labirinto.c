#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "labirinto.h"

typedef struct PILHA Elem;


Labirinto* LeLabirinto(const char *entrada)
{
    int i,j;

    FILE* arquivo;
    arquivo = fopen(entrada,"r");
    if(arquivo==NULL)
        printf("O arquivo nao existe!!!");

    Labirinto *labirinto = (Labirinto*) malloc(sizeof(Labirinto));
    if(labirinto!=NULL)
    {
        fscanf(arquivo,"%d %d %d %d %d", &labirinto->N, &labirinto->x, &labirinto->y, &labirinto->sx, &labirinto->sy);

        labirinto->mapa = (unsigned char**) malloc (labirinto->N * sizeof(unsigned char*));
        for(i=0; i<labirinto->N; i++)
        {
            labirinto->mapa[i] = (unsigned char*) malloc (labirinto->N*sizeof(unsigned char));
        }

        for(i=0; i<labirinto->N; i++)
        {
            for(j=0; j<labirinto->N; j++)
            {
                int aux;
                fscanf(arquivo,"%d", &aux);
                labirinto->mapa[i][j]= aux;
            }
        }
    }
    fclose(arquivo);
    return labirinto;
}

int criaSolucao(Labirinto *aux)
{
   int **sol;
   int i,j;

   sol = (int**) malloc (aux->N*sizeof(int*));
   for (i=0;i<aux->N; i++)
   {
       sol[i]=(int*) malloc (aux->N*sizeof(int));
   }

    for (i=0; i<aux->N; i++)
    {
        for(j=0; j<aux->N; j++)
        {
            sol[i][j] = 0;
        }
    }

   return sol;
}

int CaminhaLabirintoRecursivo(Labirinto* lab, int x, int y,int ** sol)
{
            if (x==lab->sx && y==lab->sy)
            {
                sol[x][y]=1;
                return 1;
            }
            else if (lab->mapa[x][y]==0 && sol[x][y]==0)
            {
                sol[x][y]=1;
                if(x+1<lab->N)
                    if (CaminhaLabirintoRecursivo(lab, x+1, y, sol)==1)
                    return 1;
                if(y+1<lab->N)
                    if (CaminhaLabirintoRecursivo(lab, x, y+1, sol)==1)
                    return 1;
                if(x-1>0)
                    if (CaminhaLabirintoRecursivo(lab, x-1, y, sol)==1)
                    return 1;
                if(y-1>0)
                    if (CaminhaLabirintoRecursivo(lab, x, y-1, sol)==1)
                    return 1;
                sol[x][y]=0;
            }

return 0;

}

void imprimeArquivo (Labirinto* lab, int **sol, char *nome)

{
    FILE* arquivo;
    arquivo = fopen(nome,"w");

    int i, j;

        for (i=0; i<lab->N; i++)// Apaga os numeros 9 gerados na função Iterativa e substitui por 0
    {
        for(j=0; j<lab->N; j++)
        {
            if(sol[i][j]==9)
                sol[i][j]=0;
        }
    }

    for (i=0; i<lab->N; i++)
    {
        for(j=0; j<lab->N; j++)
        {
            fprintf(arquivo,"%d", sol[i][j]);
        }
        fprintf(arquivo,"\n");
    }
}

void liberaSol(Labirinto* lab, int **sol)

{
    int i;
    for (i=0; i<lab->N; i++)
    {
        free (sol[i]);
    }
    free(sol);
}

void liberaMapa(Labirinto* lab)
{
    int i;
    for (i=0; i<lab->N; i++)
    {
        free (lab->mapa[i]);
    }
    free(lab);
}

Pilha* CriaPilha()
{
    Pilha* plh = (Pilha*) malloc (sizeof(Pilha));
    if(plh!=NULL)
        *plh = NULL;
    return plh;
}

int inserePilha(Pilha* plh, int x, int y)
{
    if(plh==NULL)
        return 0;
    Elem* celula = (Elem*) malloc(sizeof(Elem));
    if(celula==NULL)
        return 0;
    struct cordenadas dados = {x,y};

    celula->cord = dados;
    celula->prox = (*plh);
    *plh = celula;

    return 1;
}

int retiraPilha(Pilha* plh)
{
    if (plh==NULL)
        return 0;
    if((*plh)==NULL)
        return 0;

    Elem* celula = *plh;
    *plh = celula->prox;
    free(celula);

    return 0;
}

int CaminhaLabirintoIterativo(Labirinto* lab, int **sol){

Pilha *pi;

pi = CriaPilha();
inserePilha(pi, lab->x, lab->y);// Insere a entrada do labirinto na pilha.

while(pi!=NULL)
{
    if((*pi)->cord.x==lab->sx && (*pi)->cord.y==lab->sy)//Verifica se a posição atual é a da espada
            {
            sol[(*pi)->cord.x][(*pi)->cord.y]=1;
            break;
            }
              else if(sol[(*pi)->cord.x][(*pi)->cord.y]!=9)
               {// Verifica se a matriz sol e o labirinto são zeros.
                if (lab->mapa[(*pi)->cord.x][(*pi)->cord.y]==0 && sol[(*pi)->cord.x][(*pi)->cord.y]==0)
                   sol[(*pi)->cord.x][(*pi)->cord.y]=1;
               }
        if((*pi)->cord.x+1<lab->N)//Evita entrar em endereço invalido(Segmentation Fault)
        {
                if(sol[(*pi)->cord.x+1][(*pi)->cord.y]!=9)
               {//Verifica o caminho da direita
                    if (lab->mapa[(*pi)->cord.x+1][(*pi)->cord.y]==0 && sol[(*pi)->cord.x+1][(*pi)->cord.y]==0)
                    {
                    inserePilha(pi,(*pi)->cord.x+1,(*pi)->cord.y);
                    continue;
                    }
               }
        }

        if((*pi)->cord.y+1<lab->N)//Evita entrar em endereço invalido(Segmentation Fault)
        {
               if((sol[(*pi)->cord.x][(*pi)->cord.y+1]!=9) && (sol[(*pi)->cord.y+1<lab->N]))
               {//Verifica o caminho para baixo
                    if (lab->mapa[(*pi)->cord.x][(*pi)->cord.y+1]==0 && sol[(*pi)->cord.x][(*pi)->cord.y+1]==0)
                    {
                    inserePilha(pi,(*pi)->cord.x,(*pi)->cord.y+1);
                    continue;
                    }
               }
        }

        if((*pi)->cord.x-1>=0)//Evita entrar em endereço invalido(Segmentation Fault)
        {
                if(sol[(*pi)->cord.x-1][(*pi)->cord.y]!=9)
               {//Verifica o caminho a esquerda
                    if (lab->mapa[(*pi)->cord.x-1][(*pi)->cord.y]==0 && sol[(*pi)->cord.x-1][(*pi)->cord.y]==0)
                    {
                    inserePilha(pi,(*pi)->cord.x-1,(*pi)->cord.y);
                    continue;
                    }
               }
        }

        if((*pi)->cord.y-1>=0)//Evita entrar em endereço invalido(Segmentation Fault)
        {
            if(sol[(*pi)->cord.x][(*pi)->cord.y-1]!=9)
               {//Verifica o caminho para cima
                    if (lab->mapa[(*pi)->cord.x][(*pi)->cord.y-1]==0 && sol[(*pi)->cord.x][(*pi)->cord.y-1]==0)
                    {
                    inserePilha(pi,(*pi)->cord.x,(*pi)->cord.y-1);
                    continue;
                    }
                }
        //Se nenhum dos caminhos for valido, desempilha a ultima coordenada.
        sol[(*pi)->cord.x][(*pi)->cord.y]=9;// Marcação de coordenada já visitada
        retiraPilha(pi);
        }

}

liberaPilha(pi);//Libera a estrutura Pilha

return 0;
}

void liberaPilha(Pilha* plh)
{
    while(plh!=NULL)
    {
    if (plh==NULL)
        return 0;
    if((*plh)==NULL)
        return 0;

    Elem* celula = *plh;
    *plh = celula->prox;
    free(celula);
    }

    free(plh);
}
