#include <iostream>
#include "Tetris.h"

using namespace std;


int main(){
    Tetris teste(9);

    teste.adicionaForma(0,0,'I',180);
    teste.adicionaForma(5,5,'J',180);
    teste.adicionaForma(5,10,'L',180);
    teste.adicionaForma(5,15,'O',180);
    teste.adicionaForma(5,20,'S',180);
    teste.adicionaForma(5,25,'T',180);
    teste.adicionaForma(5,30,'Z',180);

    teste.imprimePeca();
    teste.imprimeJogo();
    return 0;
}