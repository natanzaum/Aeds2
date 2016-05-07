#ifndef CORCRUZADA_H_INCLUDED
#define CORCRUZADA_H_INCLUDED

typedef struct
{
    int x;
    int y;
} Ponto;

typedef struct
{
    int c; // n�mero de colunas na imagem
    int l; // n�mero de linhas na imagem
    unsigned char maximo; // valor m�ximo para cada pixel
    unsigned char **dados; // vari�vel para armazenar os pixels da imagem (matriz)
} PGM;

/*-----------------------------------------------------------------------
Prot�tipo: PGM *LePGM(char* entrada);
Fun��o: L� um arquivo �.pgm�, armazena o n�mero de colunas, n�mero de linhas, quantidade de pixels e cria uma matriz
que armazena os pixels.
Entrada: A fun��o recebe um ponteiro do tipo char que cont�m o nome do arquivo definido pelo usu�rio.
Sa�da: A fun��o retorna uma estrutura do tipo PGM contendo os dados do arquivo.
------------------------------------------------------------------------*/
PGM *LePGM(char* entrada);

/*-----------------------------------------------------------------------
Prot�tipo: int CorrelacaoCruzada(PGM *cena, PGM *obj, Ponto p);
Fun��o: A fun��o correla��o cruzada efetua o c�lculo da correla��o entre a imagem da cena na posi��o (X,Y) e a imagem do objeto e retorna este valor.
Entrada: Uma estrutura do tipo PGM que cont�m a cena, uma estrutura do tipo PGM que cont�m o objeto e uma estrutura do tipo Ponto que cont�m as coordenadas XY.
Sa�da: O valor da correla��o cruzada entre a imagem Cena e a imagem Objeto.
------------------------------------------------------------------------*/
int CorrelacaoCruzada(PGM *cena, PGM *obj, Ponto p);

/*-----------------------------------------------------------------------
Prot�tipo: Ponto JanelaDeslizante(PGM *cena, PGM *obj);
Fun��o: Aplica o algoritmo da janela deslizante, definindo um ponto X.Y e passando esse ponto para a fun��o int CorrelacaoCruzada.
Ap�s o c�lculo, a fun��o compara os valores recebidos com os calculados anteriormente. A fun��o ir� armazenar o maior valor e os pontos onde foi calculado este valor.
Entrada: Duas estruturas do tipo PGM, uma contendo os dados da Cena e a outra os dados do Objeto.
Sa�da: Uma estrutura do tipo Ponto contendo os pontos X.Y onde ocorreu o match da cena com o objeto.
------------------------------------------------------------------------*/
Ponto JanelaDeslizante(PGM *cena, PGM *obj);

/*-----------------------------------------------------------------------
Prot�tipo: void libera_pgm(PGM *cena);
Fun��o: Libera as estruturas alocadas dinamicamente usando "malloc"
Entrada: Recebe uma estrutura do tipo PGM.
Sa�da: N�o retorna nenhuma sa�da
------------------------------------------------------------------------*/
void libera_pgm(PGM *cena);

/*-----------------------------------------------------------------------
Prot�tipo: void grava_pontos(Ponto p, char* entrada);
Fun��o: Respons�vel por gravar os dados no arquivo.txt que o usu�rio definiu como entrada atrav�s da linha de comando.
Entrada: Estrutura do tipo Ponto, contendo os pontos X e Y na regi�o que deu match e o nome do arquivo.txt
Sa�da: Um arquivo.txt contendo os pontos onde ocorreu o match.
------------------------------------------------------------------------*/
void grava_pontos(Ponto p, char* entrada);


#endif // CORCRUZADA_H_INCLUDED
