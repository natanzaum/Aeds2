#ifndef LABFUN_H_INCLUDED
#define LABFUN_H_INCLUDED

typedef struct {
int N; // Dimensão do labirinto, lmebre-se que o mesmo é N x N
int x; // Coordenada x da entrada
int y; // Coordenada y da entrada
int sx; // Coordenada x da espada
int sy; // Coordenada y da espada
unsigned char **mapa; // variável para armazenar o mapa (matriz)
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
Função: Cria uma pilha vazia.
Entrada: Não recebe nada como entrada.
Saída: Retorna um ponteiro para o nó cabeça da pilha.
----------------------------------------------------------------*/
Pilha* CriaPilha();

/*--------------------------------------------------------------
Prototipo:int inserePilha(Pilha* plh, int x, int y)
Função: Insere as coordenadas X e Y no topo da pilha.
Entrada: Recebe uma Estrutura do tipo Pilha e dois inteiros(Coordenadas X e Y).
Saída: Retorna um inteiro.
----------------------------------------------------------------*/
int inserePilha(Pilha* plh, int x, int y);

/*--------------------------------------------------------------
Prototipo: int retiraPilha(Pilha* plh
Função: Retira uma celula da pilha.
Entrada: Recebe uma estrutura do tipo Pilha.
Saída: Retorna um inteiro.
----------------------------------------------------------------*/
int retiraPilha(Pilha* plh);

/*--------------------------------------------------------------
Prototipo: void imprimeDesempilha(Labirinto* lab, int **sol, char *nome)
Função: Imprime a solução do Labirinto
Entrada: Recebe uma matriz de inteiros (int **sol), uma estrutura do tipo Labirinto e um nome para o arquivo TXT.
Saída: Grava um arquivo .TXT com a solução do labirinto. A função é do tipo void e não retorna nada.
----------------------------------------------------------------*/
void imprimeIterativo(Labirinto* lab, int **sol, char *nome);

/*--------------------------------------------------------------
Prototipo: Labirinto* LeLabirinto(const char * entrada)
Função: Lê um arquivo.txt contendo o labirinto.
Entrada: Recebe o nome do arquivo que contém o labirinto.
Saída: Retorna uma estrutura do tipo Labirinto contendo os dados do arquivo indicado pelo usuário.
----------------------------------------------------------------*/
Labirinto* LeLabirinto(const char * entrada);

/*--------------------------------------------------------------
Prototipo: CaminhaLabirintoRecursivo(Labirinto* lab, int x, int y,int **sol);
Função: Resolve o labirinto usando um algoritimo recursivo.
Entrada: Recebe uma estrutuda do tipo Labirinto, as coordenadas X e Y de entrada, e uma matriz solução(int **sol).
Saída: Retorna um inteiro: 1 para caminho valido e 0 para caminho invalido.
----------------------------------------------------------------*/
int CaminhaLabirintoRecursivo(Labirinto* lab, int x, int y,int **sol);

/*--------------------------------------------------------------
Prototipo: int CaminhaLabirintoIterativo(Labirinto* lab,int **sol);
Função: Resolve o labirinto usando um algoritimo iterativo.
Entrada: Recebe uma estrutura do tipo Labirinto e uma matriz solução(int **sol)
Saída: Retorna um inteiro: 1 para caminho valido e 0 para caminho invalido.
----------------------------------------------------------------*/
int CaminhaLabirintoIterativo(Labirinto* lab,int **sol);

/*--------------------------------------------------------------
Prototipo:int criaSolucao(Labirinto *aux)
Função: Cria uma matriz int **sol contendo somente zeros.
Entrada: Recebe uma estrutura do tipo Labirinto e usa os dados desta para gerar a matriz
Saída: Retorna uma matriz do tipo int **sol toda zerada.
----------------------------------------------------------------*/
int criaSolucao(Labirinto *aux);

/*--------------------------------------------------------------
Prototipo: void imprimeArquivo (int **sol, char *nome);
Função: Grava no arquivo o caminho até a espada.
Entrada: Recebe uma variavel do tipo **sol que contém o caminho realizado por Teseu até a espada, e um nome de arquivo.
Saída: A função grava um arquivo com o nome informado pelo usuario contendo o caminho percorrido por Teseu até a espada.
----------------------------------------------------------------*/
void imprimeArquivo (Labirinto* lab, int **sol, char *nome);

/*--------------------------------------------------------------
Prototipo: void liberaMapa(Labirinto* lab);
Função: Libera uma estrutura do tipo Labirinto alocada de forma dinamica.
Entrada: Recebe uma estrutura do tipo Labirinto, que contem os dados do mapa, entrada, localização da espada, etc.
Saída: Não possui saída. Apenas libera uma estrutura Labirinto
----------------------------------------------------------------*/
void liberaMapa(Labirinto* lab);

/*--------------------------------------------------------------
Prototipo: void liberaSol(Labirinto* lab, int **sol);
Função: A função recebe uma estrutura do tipo Labirinto, e utiliza os dados armazenados nela para liberar a matriz int **sol.
Entrada: Recebe um ponteiro de ponteiro do tipo int (int **sol), e uma estrutura do tipo Labirinto que contem os dados do mapa.
Saída: Não possui saída. Apenas libera a  variavel int **sol
----------------------------------------------------------------*/
void liberaSol(Labirinto* lab, int **sol);

/*--------------------------------------------------------------
Prototipo: void liberaFila(Pilha* plh);
Função: A função recebe uma estrutura do tipo pilha e libera a memoria alocada de forma dinamica.
Entrada: A função recebe uma estrutura do tipo Pilha
Saída: Não possui saída. Apenas libera a pilha.
----------------------------------------------------------------*/
void liberaPilha(Pilha* plh);

#endif // LABFUN_H_INCLUDED
