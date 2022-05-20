#ifndef TETRIS_H
#define TETRIS_H
#include <string>

using namespace std;

class Tetris{
    private:
        char **jogo;        //array dinamico de arrays dinamicos que representa o jogo
        int colunas;        //quantidade de colunas
        int *alturas;       //vetor que armazena a altura de cada coluna

        //matrizes das pecas
        char **pecaI;
        char **pecaJ;
        char **pecaL;
        char **pecaO;
        char **pecaS;
        char **pecaT;
        char **pecaZ;


    public:

        //////////////Construtores//////////////
        Tetris(const int c);
        Tetris(const Tetris &);

        //////////////Gets//////////////
        char get(const int c, const int l) const;
        int getNumColunas() const;
        int getAltura(const int c) const;
        int getAltura() const;


        //////////////Remove/Adiciona/ETC//////////////
        void removeColuna(const int c);
        void removeLinhasCompletas();
        bool adicionaForma(const int coluna, const int linha, const char id, const int rotacao);


        //////////////Operadores//////////////
        Tetris &operator=(const Tetris &other);

        
        //////////////Metodos auxiliares//////////////
        void imprimePeca();
        void imprimeJogo();
        void cleanPeca(const char id);
        void rotacionaPeca(const char id, const int rotacao);

        //////////////Destrutor//////////////
        ~Tetris();
};

#endif