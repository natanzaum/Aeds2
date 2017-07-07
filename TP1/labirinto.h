#ifndef LABFUN_H_INCLUDED
#define LABFUN_H_INCLUDED

typedef struct {
int N; // Dimens�o do labirinto, lmebre-se que o mesmo � N x N
int x; // Coordenada x da entrada
int y; // Coordenada y da entrada
int sx; // Coordenada x da espada
int sy; // Coordenada y da espada
unsigned char **mapa; // vari�vel para armazenar o mapa (matriz)
} Labirinto;

struct cordenadas{
 int x;
 int y;
};

struct PILHA{// Estrutura da Pilha
    struct cordenadas cord;
    struct PILHA *prox;
};

typedef struct PILHA* Pilha;

/*--------------------------------------------------------------
Prototipo: Pilha* CriaPilha()
Fun��o: Cria uma pilha vazia.
Entrada: N�o recebe nada como entrada.
Sa�da: Retorna um ponteiro para o n� cabe�a da pilha.
----------------------------------------------------------------*/
Pilha* CriaPilha();

/*--------------------------------------------------------------
Prototipo:int inserePilha(Pilha* plh, int x, int y)
Fun��o: Insere as coordenadas X e Y no topo da pilha.
Entrada: Recebe uma Estrutura do tipo Pilha e dois inteiros(Coordenadas X e Y).
Sa�da: Retorna um inteiro.
----------------------------------------------------------------*/
int inserePilha(Pilha* plh, int x, int y);

/*--------------------------------------------------------------
Prototipo: int retiraPilha(Pilha* plh
Fun��o: Retira uma celula da pilha.
Entrada: Recebe uma estrutura do tipo Pilha.
Sa�da: Retorna um inteiro.
----------------------------------------------------------------*/
int retiraPilha(Pilha* plh);

/*--------------------------------------------------------------
Prototipo: void imprimeDesempilha(Labirinto* lab, int **sol, char *nome)
Fun��o: Imprime a solu��o do Labirinto
Entrada: Recebe uma matriz de inteiros (int **sol), uma estrutura do tipo Labirinto e um nome para o arquivo TXT.
Sa�da: Grava um arquivo .TXT com a solu��o do labirinto. A fun��o � do tipo void e n�o retorna nada.
----------------------------------------------------------------*/
void imprimeIterativo(Labirinto* lab, int **sol, char *nome);

/*--------------------------------------------------------------
Prototipo: Labirinto* LeLabirinto(const char * entrada)
Fun��o: L� um arquivo.txt contendo o labirinto.
Entrada: Recebe o nome do arquivo que cont�m o labirinto.
Sa�da: Retorna uma estrutura do tipo Labirinto contendo os dados do arquivo indicado pelo usu�rio.
----------------------------------------------------------------*/
Labirinto* LeLabirinto(const char * entrada);

/*--------------------------------------------------------------
Prototipo: CaminhaLabirintoRecursivo(Labirinto* lab, int x, int y,int **sol);
Fun��o: Resolve o labirinto usando um algoritimo recursivo.
Entrada: Recebe uma estrutuda do tipo Labirinto, as coordenadas X e Y de entrada, e uma matriz solu��o(int **sol).
Sa�da: Retorna um inteiro: 1 para caminho valido e 0 para caminho invalido.
----------------------------------------------------------------*/
int CaminhaLabirintoRecursivo(Labirinto* lab, int x, int y,int **sol);

/*--------------------------------------------------------------
Prototipo: int CaminhaLabirintoIterativo(Labirinto* lab,int **sol);
Fun��o: Resolve o labirinto usando um algoritimo iterativo.
Entrada: Recebe uma estrutura do tipo Labirinto e uma matriz solu��o(int **sol)
Sa�da: Retorna um inteiro: 1 para caminho valido e 0 para caminho invalido.
----------------------------------------------------------------*/
int CaminhaLabirintoIterativo(Labirinto* lab,int **sol);

/*--------------------------------------------------------------
Prototipo:int criaSolucao(Labirinto *aux)
Fun��o: Cria uma matriz int **sol contendo somente zeros.
Entrada: Recebe uma estrutura do tipo Labirinto e usa os dados desta para gerar a matriz
Sa�da: Retorna uma matriz do tipo int **sol toda zerada.
----------------------------------------------------------------*/
int criaSolucao(Labirinto *aux);

/*--------------------------------------------------------------
Prototipo: void imprimeArquivo (int **sol, char *nome);
Fun��o: Grava no arquivo o caminho at� a espada.
Entrada: Recebe uma variavel do tipo **sol que cont�m o caminho realizado por Teseu at� a espada, e um nome de arquivo.
Sa�da: A fun��o grava um arquivo com o nome informado pelo usuario contendo o caminho percorrido por Teseu at� a espada.
----------------------------------------------------------------*/
void imprimeArquivo (Labirinto* lab, int **sol, char *nome);

/*--------------------------------------------------------------
Prototipo: void liberaMapa(Labirinto* lab);
Fun��o: Libera uma estrutura do tipo Labirinto alocada de forma dinamica.
Entrada: Recebe uma estrutura do tipo Labirinto, que contem os dados do mapa, entrada, localiza��o da espada, etc.
Sa�da: N�o possui sa�da. Apenas libera uma estrutura Labirinto
----------------------------------------------------------------*/
void liberaMapa(Labirinto* lab);

/*--------------------------------------------------------------
Prototipo: void liberaSol(Labirinto* lab, int **sol);
Fun��o: A fun��o recebe uma estrutura do tipo Labirinto, e utiliza os dados armazenados nela para liberar a matriz int **sol.
Entrada: Recebe um ponteiro de ponteiro do tipo int (int **sol), e uma estrutura do tipo Labirinto que contem os dados do mapa.
Sa�da: N�o possui sa�da. Apenas libera a  variavel int **sol
----------------------------------------------------------------*/
void liberaSol(Labirinto* lab, int **sol);

/*--------------------------------------------------------------
Prototipo: void liberaFila(Pilha* plh);
Fun��o: A fun��o recebe uma estrutura do tipo pilha e libera a memoria alocada de forma dinamica.
Entrada: A fun��o recebe uma estrutura do tipo Pilha
Sa�da: N�o possui sa�da. Apenas libera a pilha.
----------------------------------------------------------------*/
void liberaPilha(Pilha* plh);

#endif // LABFUN_H_INCLUDED
