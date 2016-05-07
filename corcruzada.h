#ifndef CORCRUZADA_H_INCLUDED
#define CORCRUZADA_H_INCLUDED

typedef struct
{
    int x;
    int y;
} Ponto;

typedef struct
{
    int c; // número de colunas na imagem
    int l; // número de linhas na imagem
    unsigned char maximo; // valor máximo para cada pixel
    unsigned char **dados; // variável para armazenar os pixels da imagem (matriz)
} PGM;

/*-----------------------------------------------------------------------
Protótipo: PGM *LePGM(char* entrada);
Função: Lê um arquivo “.pgm”, armazena o número de colunas, número de linhas, quantidade de pixels e cria uma matriz
que armazena os pixels.
Entrada: A função recebe um ponteiro do tipo char que contém o nome do arquivo definido pelo usuário.
Saída: A função retorna uma estrutura do tipo PGM contendo os dados do arquivo.
------------------------------------------------------------------------*/
PGM *LePGM(char* entrada);

/*-----------------------------------------------------------------------
Protótipo: int CorrelacaoCruzada(PGM *cena, PGM *obj, Ponto p);
Função: A função correlação cruzada efetua o cálculo da correlação entre a imagem da cena na posição (X,Y) e a imagem do objeto e retorna este valor.
Entrada: Uma estrutura do tipo PGM que contém a cena, uma estrutura do tipo PGM que contém o objeto e uma estrutura do tipo Ponto que contém as coordenadas XY.
Saída: O valor da correlação cruzada entre a imagem Cena e a imagem Objeto.
------------------------------------------------------------------------*/
int CorrelacaoCruzada(PGM *cena, PGM *obj, Ponto p);

/*-----------------------------------------------------------------------
Protótipo: Ponto JanelaDeslizante(PGM *cena, PGM *obj);
Função: Aplica o algoritmo da janela deslizante, definindo um ponto X.Y e passando esse ponto para a função int CorrelacaoCruzada.
Após o cálculo, a função compara os valores recebidos com os calculados anteriormente. A função irá armazenar o maior valor e os pontos onde foi calculado este valor.
Entrada: Duas estruturas do tipo PGM, uma contendo os dados da Cena e a outra os dados do Objeto.
Saída: Uma estrutura do tipo Ponto contendo os pontos X.Y onde ocorreu o match da cena com o objeto.
------------------------------------------------------------------------*/
Ponto JanelaDeslizante(PGM *cena, PGM *obj);

/*-----------------------------------------------------------------------
Protótipo: void libera_pgm(PGM *cena);
Função: Libera as estruturas alocadas dinamicamente usando "malloc"
Entrada: Recebe uma estrutura do tipo PGM.
Saída: Não retorna nenhuma saída
------------------------------------------------------------------------*/
void libera_pgm(PGM *cena);

/*-----------------------------------------------------------------------
Protótipo: void grava_pontos(Ponto p, char* entrada);
Função: Responsável por gravar os dados no arquivo.txt que o usuário definiu como entrada através da linha de comando.
Entrada: Estrutura do tipo Ponto, contendo os pontos X e Y na região que deu match e o nome do arquivo.txt
Saída: Um arquivo.txt contendo os pontos onde ocorreu o match.
------------------------------------------------------------------------*/
void grava_pontos(Ponto p, char* entrada);


#endif // CORCRUZADA_H_INCLUDED
