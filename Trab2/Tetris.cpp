#include "Tetris.h"
#include <iostream>
#include <cctype>

using namespace std;


//////////////Construtores//////////////
Tetris::Tetris(int c){
    this->colunas = c;
    this->alturas = new int[c];
    this->jogo = new char*[c];
    for(int i = 0; i < c; i++){
        this->alturas[i] = 0;
        this->jogo[i] = new char[1];
        this->jogo[i][0] = ' ';
    }

    //criando pecas
    this->pecaI = new char*[4];
    this->pecaJ = new char*[4];
    this->pecaL = new char*[4];
    this->pecaO = new char*[4];
    this->pecaS = new char*[4];
    this->pecaT = new char*[4];
    this->pecaZ = new char*[4];
    for(int i = 0; i < 4; i++){
        this->pecaI[i] = new char[4];
        this->pecaJ[i] = new char[4];
        this->pecaL[i] = new char[4];
        this->pecaO[i] = new char[4];
        this->pecaS[i] = new char[4];
        this->pecaT[i] = new char[4];
        this->pecaZ[i] = new char[4];
    }
    
    //preenche as pecas com espacos vazios
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){                       
            this->pecaI[i][j] = ' ';
            this->pecaJ[i][j] = ' ';
            this->pecaL[i][j] = ' ';
            this->pecaO[i][j] = ' ';
            this->pecaS[i][j] = ' ';
            this->pecaT[i][j] = ' ';
            this->pecaZ[i][j] = ' ';
        }
    }

    //Adicionando a formacao inicial das pecas
    //peca I
    this->pecaI[0][0] = 'I';
    this->pecaI[1][0] = 'I';
    this->pecaI[2][0] = 'I';
    this->pecaI[3][0] = 'I';

    
    //peca J
    this->pecaJ[0][0] = 'J';
    this->pecaJ[0][1] = 'J';
    this->pecaJ[0][2] = 'J';
    this->pecaJ[0][3] = 'J';
    this->pecaJ[1][3] = 'J';


    //peca L
    this->pecaL[0][0] = 'L';
    this->pecaL[0][1] = 'L';
    this->pecaL[0][2] = 'L';
    this->pecaL[0][3] = 'L';
    this->pecaL[1][0] = 'L';


    //peca O
    this->pecaO[0][0] = 'O';
    this->pecaO[0][1] = 'O';
    this->pecaO[1][0] = 'O';
    this->pecaO[1][1] = 'O';


    //peca S
    this->pecaS[0][1] = 'S';
    this->pecaS[0][2] = 'S';
    this->pecaS[1][0] = 'S';
    this->pecaS[1][1] = 'S';


    //peca T
    this->pecaT[0][0] = 'T';
    this->pecaT[0][1] = 'T';
    this->pecaT[0][2] = 'T';
    this->pecaT[1][1] = 'T';


    //peca Z
    this->pecaZ[0][0] = 'Z';
    this->pecaZ[0][1] = 'Z';
    this->pecaZ[1][1] = 'Z';
    this->pecaZ[1][2] = 'Z';
}

Tetris::Tetris(const Tetris &other){
    this->colunas = 0;
    this->alturas = NULL;
    this->jogo = NULL;
    this->pecaI = NULL;
    this->pecaJ = NULL;
    this->pecaL = NULL;
    this->pecaO = NULL;
    this->pecaS = NULL;
    this->pecaT = NULL;
    this->pecaZ = NULL;

    *this = other;
}


//////////////Gets//////////////
char Tetris::get(const int c, const int l) const{
    if(c < this->colunas && l < this->alturas[c])
        return this->jogo[c][l];
    else
        return ' ';
}

int Tetris::getNumColunas() const{
    return this->colunas;
}


int Tetris::getAltura(const int c) const{
    return this->alturas[c];
}

int Tetris::getAltura() const{
    int maior = 0;                                 //Variavel que armazena a maior altura até o momento
    for(int i = 0; i < this->colunas; i++){        
        if(this->alturas[i] > maior)               //Se a altura atual for maior que a armazenada na variavel maior 
            maior = this->alturas[i];              //Atribui a nova altura a variavel maior
    }
    return maior;                                  //retorna a maior altura
}




//////////////Metodos de remover/adicionar//////////////
void Tetris::removeColuna(const int c){
    char **auxJogo;                                 //cria um jogo auxiliar para armazenar o estado antigo do jogo
    int *auxAlturas;

    auxAlturas = new int[this->colunas-1];
    auxJogo = new char*[this->colunas];

    for(int i = 0; i < this->colunas; i++){
        auxJogo[i] = new char[this->alturas[i]];
    }

    for(int i = 0; i < this->colunas; i++)
        for(int j = 0; j < this->alturas[i]; j++)
            auxJogo[i][j] = this->jogo[i][j];       //atribui o jogo antigo a variavel auxiliar

    for (int i = 0; i < this->colunas; i++)
        delete []jogo[i];                           //deletamos o jogo antigo para criar um novo alocando com uma coluna a menos
    delete []jogo;

    this->jogo = new char *[this->colunas - 1];     //alocamos o novo jogo com uma coluna a menos
    
                                   
    for(int i = 0; i < this->colunas; i++){
        if(i == c){
            this->jogo[i] = new char[this->alturas[i+1]];  //se i for igual a coluna a ser retirada, atribui a proxima coluna ao jogo
            i++;
        }else{
            this->jogo[i] = new char[this->alturas[i]];
        }
    }

    for(int i = 0; i < this->colunas; i++){
        if(i == c){
               for(int j = 0; j < this->alturas[i+1]; j++){
                    this->jogo[i][j] == auxJogo[i+1][j];       //se i for igual a coluna a ser retirada, atribui a proxima coluna ao jogo
                    i++;
               }
           }else{
                for(int j = 0; j < this->alturas[i]; j++){     //caso contrario atribui normalmente
                    this->jogo[i][j] == auxJogo[i][j];
                }
            }
    }

    int aux = 0;
    for(int i = 0; i < this->colunas; i++){
        if(i == c){
            auxAlturas[aux] = this->alturas[i+1];
        }else{
            auxAlturas[aux] = this->alturas[i];
            aux++;
        }
    }

    delete []alturas;

    this->colunas -= 1;

    this->alturas = new int[this->colunas];

    for(int i = 0; i < this->colunas; i++){
        this->alturas[i] = auxAlturas[i];
    }

    delete []auxAlturas;

    for (int i = 0; i < this->colunas; i++)
        delete []auxJogo[i];                         //depois de tudo atribuido deletamos a variavel que armazena o estado antigo do jogo
    delete []auxJogo;

}



void Tetris::removeLinhasCompletas(){
    int cont = 0;                                    //contador de caracteres
    int maxAltura = getAltura();

    for(int i = 0; i < maxAltura; i++){
        for(int j = 0; j < this->colunas; j++){
            if(isalpha(this->jogo[i][j])){
                cont++;
            }
        }
        if(cont == this->colunas){                                 //se a linha estiver completa
            for(int k = 0; k < this->colunas; k++){
                this->jogo[i][k] = ' ';                            //apagamos o conteudo da mesma
            }
            for(int l = 0;l < this->colunas; l++){
                for(int p = i; p < maxAltura; p++){
                    swap(this->jogo[l][p],this->jogo[l][p+1]);     //jogamos os espacos em branco pra ultima posicao "descendo" todos os outros elementos
                }
            }
        }
        cont = 0;
    }

    for(int i = 0; i < this->colunas; i++){
        this->alturas[i] -= 1;
    }

}


bool Tetris::adicionaForma(const int coluna, const int linha, const char id, const int rotacao){
    rotacionaPeca(id, rotacao);
    int cont = 0;
    if(id == 'I'){
        if(rotacao == 90 || rotacao == 270){
            if(!isalpha(get(coluna,linha)) && !isalpha(get(coluna+1,linha)) 
            && !isalpha(get(coluna+2,linha)) && !isalpha(get(coluna+3,linha))){                           //Verifica se pode colocar a peca ja rotacionada no jogo
                this->jogo[coluna][linha] = 'I';                                                          //insere a peca no jogo caso verdadeiro
                this->jogo[coluna+1][linha] = 'I';
                this->jogo[coluna+2][linha] = 'I';
                this->jogo[coluna+3][linha] = 'I';
            }else
                return false;                                                                             //retorna falso caso contrario
        }else if(rotacao == 0 || rotacao == 180){
            if(!isalpha(get(coluna,linha)) && !isalpha(get(coluna,linha+1)) 
            && !isalpha(get(coluna,linha+2)) && !isalpha(get(coluna,linha+3))){
                this->jogo[coluna][linha] = 'I';
                this->jogo[coluna][linha+1] = 'I';
                this->jogo[coluna][linha+2] = 'I';
                this->jogo[coluna][linha+3] = 'I';
            }else
                return false;
        }
    }else if(id == 'J'){
        if(rotacao == 90){
            if(!isalpha(get(coluna+1,linha)) && !isalpha(get(coluna+1,linha-1)) 
            && !isalpha(get(coluna+1,linha-2)) && !isalpha(get(coluna+1,linha-3)) 
            && !isalpha(get(coluna,linha-3))){
                this->jogo[coluna+1][linha] = 'J';
                this->jogo[coluna+1][linha-1] = 'J';
                this->jogo[coluna+1][linha-2] = 'J';
                this->jogo[coluna+1][linha-3] = 'J';
                this->jogo[coluna][linha-3] = 'J';
            }else
                return false;
        }else if(rotacao == 180){
            if(!isalpha(get(coluna,linha)) && !isalpha(get(coluna,linha-1)) 
            && !isalpha(get(coluna+1,linha-1)) && !isalpha(get(coluna+2, linha-1)) 
            && !isalpha(get(coluna+3, linha-1))){
                this->jogo[coluna][linha] = 'J';
                this->jogo[coluna][linha-1] = 'J';
                this->jogo[coluna+1][linha-1] = 'J';
                this->jogo[coluna+2][linha-1] = 'J';
                this->jogo[coluna+3][linha-1] = 'J';
            }else
                return false;
        }else if(rotacao == 270){
            if(!isalpha(get(coluna,linha)) && !isalpha(get(coluna+1,linha))
            && !isalpha(get(coluna,linha-1)) && !isalpha(get(coluna,linha-2))
            && !isalpha(get(coluna,linha-3))){
                this->jogo[coluna][linha] = 'J';
                this->jogo[coluna+1][linha] = 'J';
                this->jogo[coluna][linha-1] = 'J';
                this->jogo[coluna][linha-2] = 'J';
                this->jogo[coluna][linha-3] = 'J';
            }else
                return false;
        }else if(rotacao == 0){
            if(!isalpha(get(coluna,linha)) && !isalpha(get(coluna+1,linha))
            && !isalpha(get(coluna+2,linha)) && !isalpha(get(coluna+3,linha))
            && !isalpha(get(coluna+3,linha-1))){
                this->jogo[coluna][linha] = 'J';
                this->jogo[coluna+1][linha] = 'J';
                this->jogo[coluna+2][linha] = 'J';
                this->jogo[coluna+3][linha] = 'J';
                this->jogo[coluna+3][linha-1] = 'J';
            }else
                return false;
        }
    }else if(id == 'L'){
        if(rotacao == 90){
            if(!isalpha(get(coluna,linha)) && !isalpha(get(coluna+1,linha))
            && !isalpha(get(coluna+1,linha-1)) && !isalpha(get(coluna+1,linha-2))
            && !isalpha(get(coluna+1,linha-3))){
                this->jogo[coluna][linha] = 'L';
                this->jogo[coluna+1][linha] = 'L';
                this->jogo[coluna+1][linha-1] = 'L';
                this->jogo[coluna+1][linha-2] = 'L';
                this->jogo[coluna+1][linha-3] = 'L';
            }else
                return false;
        }else if(rotacao == 180){
            if(!isalpha(get(coluna,linha-1)) && !isalpha(get(coluna+1,linha-1))
            && !isalpha(get(coluna+2,linha-1)) && !isalpha(get(coluna+3,linha-1))
            && !isalpha(get(coluna+3,linha))){
                this->jogo[coluna][linha-1] = 'L';
                this->jogo[coluna+1][linha-1] = 'L';
                this->jogo[coluna+2][linha-1] = 'L';
                this->jogo[coluna+3][linha-1] = 'L';
                this->jogo[coluna+3][linha] = 'L';
            }else
                return false;
        }else if(rotacao == 270){
            if(!isalpha(get(coluna,linha)) && !isalpha(get(coluna,linha-1))
            && !isalpha(get(coluna,linha-2)) && !isalpha(get(coluna,linha-3))
            && !isalpha(get(coluna+1,linha-3))){
                this->jogo[coluna][linha] = 'L';
                this->jogo[coluna][linha-1] = 'L';
                this->jogo[coluna][linha-2] = 'L';
                this->jogo[coluna][linha-3] = 'L';
                this->jogo[coluna+1][linha-3] = 'L';
            }else
                return false;
        }else if(rotacao == 0){
            if(!isalpha(get(coluna,linha)) && !isalpha(get(coluna,linha-1))
            && !isalpha(get(coluna+1,linha)) && !isalpha(get(coluna+2,linha))
            && !isalpha(get(coluna+3,linha))){
                this->jogo[coluna][linha] = 'L';
                this->jogo[coluna][linha-1] = 'L';
                this->jogo[coluna+1][linha] = 'L';
                this->jogo[coluna+2][linha] = 'L';
                this->jogo[coluna+3][linha] = 'L';
            }else
                return false;
        }
    }else if(id == 'O'){
        if(!isalpha(get(coluna,linha)) && !isalpha(get(coluna+1,linha))
        && !isalpha(get(coluna,linha-1)) && !isalpha(get(coluna+1,linha-1))){
            this->jogo[coluna][linha] = 'O';
            this->jogo[coluna+1][linha] = 'O';
            this->jogo[coluna][linha-1] = 'O';
            this->jogo[coluna+1][linha-1] = 'O';
        }else
            return false;
    }else if(id == 'S'){
        if(rotacao == 90 || rotacao == 270){
            if(!isalpha(get(coluna,linha)) && !isalpha(get(coluna,linha-1))
            && !isalpha(get(coluna+1,linha-1)) && !isalpha(get(coluna+1,linha-2))){
                this->jogo[coluna][linha] = 'S';
                this->jogo[coluna][linha-1] = 'S';
                this->jogo[coluna+1][linha-1] = 'S';
                this->jogo[coluna+1][linha-2] = 'S';
            }else
                return false;
        }else if(rotacao == 180 || rotacao == 0){
            if(!isalpha(get(coluna+1,linha)) && !isalpha(get(coluna+2,linha))
            && !isalpha(get(coluna,linha-1)) && !isalpha(get(coluna+1,linha-1))){
                this->jogo[coluna][linha] = 'S';
                this->jogo[coluna+1][linha] = 'S';
                this->jogo[coluna][linha-1] = 'S';
                this->jogo[coluna+1][linha-1] = 'S';
            }else
                return false;
        }
    }else if(id == 'T'){
        if(rotacao == 90){
            if(!isalpha(get(coluna+1,linha)) && !isalpha(get(coluna,linha-1))
            && !isalpha(get(coluna+1,linha-1)) && !isalpha(get(coluna+1,linha-2))){
                this->jogo[coluna+1][linha] = 'T';
                this->jogo[coluna][linha-1] = 'T';
                this->jogo[coluna+1][linha-1] = 'T';
                this->jogo[coluna+1][linha-2] = 'T';
            }else
                return false;
        }else if(rotacao == 180){
            if(!isalpha(get(coluna+1,linha)) && !isalpha(get(coluna,linha-1))
            && !isalpha(get(coluna+1,linha-1)) && !isalpha(get(coluna+2,linha-1))){
                this->jogo[coluna+1][linha] = 'T';
                this->jogo[coluna][linha-1] = 'T';
                this->jogo[coluna+1][linha-1] = 'T';
                this->jogo[coluna+2][linha-1] = 'T';
            }else
                return false;
        }else if(rotacao == 270){
            if(!isalpha(get(coluna,linha)) && !isalpha(get(coluna,linha-1))
            && !isalpha(get(coluna,linha-2)) && !isalpha(get(coluna+1,linha-1))){
                this->jogo[coluna][linha] = 'T';
                this->jogo[coluna][linha-1] = 'T';
                this->jogo[coluna][linha-2] = 'T';
                this->jogo[coluna+1][linha-1] = 'T';
            }else
                return false;
        }else if(rotacao == 0){
            if(!isalpha(get(coluna,linha)) && !isalpha(get(coluna+1,linha))
            && !isalpha(get(coluna+2,linha)) && !isalpha(get(coluna+1,linha-1))){
                this->jogo[coluna][linha] = 'T';
                this->jogo[coluna+1][linha] = 'T';
                this->jogo[coluna+2][linha] = 'T';
                this->jogo[coluna+1][linha-1] = 'T';
            }else
                return false;
        }
    }else if(id == 'Z'){
        if(rotacao == 90 || rotacao == 270){
            if(!isalpha(get(coluna+1,linha)) && !isalpha(get(coluna+1,linha+1))
            && !isalpha(get(coluna,linha-1)) && !isalpha(get(coluna,linha-2))){
                this->jogo[coluna+1][linha] = 'Z';
                this->jogo[coluna+1][linha+1] = 'Z';
                this->jogo[coluna][linha-1] = 'Z';
                this->jogo[coluna][linha-2] = 'Z';
            }else
                return false;
        }else if(rotacao == 0 || rotacao == 180){
            if(!isalpha(get(coluna,linha)) && !isalpha(get(coluna+1,linha))
            && !isalpha(get(coluna+1,linha-1)) && !isalpha(get(coluna+2,linha-1))){
                this->jogo[coluna][linha] = 'Z';
                this->jogo[coluna+1][linha] = 'Z';
                this->jogo[coluna+1][linha-1] = 'Z';
                this->jogo[coluna+2][linha-1] = 'Z';
            }else
                return false;
        }
    }
    return true;
}

void Tetris::imprimeJogo(){
    for(int i = 0; i < this->colunas; i++){
        for(int j = 0; j < getAltura(); j++){
            cout << this->jogo[i][j];
        }
    cout << "\n";
    }
}



//////////////Metodos referente as pecas//////////////
void Tetris::rotacionaPeca(const char id, const int rotacao){
    if(id == 'I'){
        if(rotacao == 90 || rotacao == 270){
            cleanPeca(id);
            this->pecaI[0][0] = 'I';
            this->pecaI[0][1] = 'I';
            this->pecaI[0][2] = 'I';
            this->pecaI[0][3] = 'I';
        }else if(rotacao == 0 || rotacao == 180){
            return;
        }
    }else if(id == 'J'){
        if(rotacao == 90){
            cleanPeca(id);
            this->pecaJ[0][1] = 'J';
            this->pecaJ[1][1] = 'J';
            this->pecaJ[2][1] = 'J';
            this->pecaJ[3][1] = 'J';
            this->pecaJ[3][0] = 'J';
        }else if(rotacao == 180){
            cleanPeca(id);
            this->pecaJ[0][0] = 'J';
            this->pecaJ[1][0] = 'J';
            this->pecaJ[1][1] = 'J';
            this->pecaJ[1][2] = 'J';
            this->pecaJ[1][3] = 'J';
        }else if(rotacao == 270){
            cleanPeca(id);
            this->pecaJ[0][0] = 'J';
            this->pecaJ[0][1] = 'J';
            this->pecaJ[1][0] = 'J';
            this->pecaJ[2][0] = 'J';
            this->pecaJ[3][0] = 'J';
        }else if(rotacao == 0){
            return;
        }
    }else if(id == 'L'){
        if(rotacao == 90){
            cleanPeca(id);
            this->pecaL[0][0] = 'L';
            this->pecaL[0][1] = 'L';
            this->pecaL[1][1] = 'L';
            this->pecaL[2][1] = 'L';
            this->pecaL[3][1] = 'L';
        }else if(rotacao == 180){
            cleanPeca(id);
            this->pecaL[0][3] = 'L';
            this->pecaL[1][0] = 'L';
            this->pecaL[1][1] = 'L';
            this->pecaL[1][2] = 'L';
            this->pecaL[1][3] = 'L';
        }else if(rotacao == 270){
            cleanPeca(id);
            this->pecaL[0][0] = 'L';
            this->pecaL[1][0] = 'L';
            this->pecaL[2][0] = 'L';
            this->pecaL[3][0] = 'L';
            this->pecaL[3][1] = 'L';
        }else if(rotacao == 0){
            return;
        }
    }else if(id == 'O'){
        return;
    }else if(id == 'S'){
        if(rotacao == 90 || rotacao == 270){
            cleanPeca(id);
            this->pecaS[0][0] = 'S';
            this->pecaS[1][0] = 'S';
            this->pecaS[1][1] = 'S';
            this->pecaS[2][1] = 'S';
        }else if(rotacao == 180 || rotacao == 0){ 
            return;
        }
    }else if(id == 'T'){
        if(rotacao == 90){
            cleanPeca(id);
            this->pecaT[0][1] = 'T';
            this->pecaT[1][1] = 'T';
            this->pecaT[1][0] = 'T';
            this->pecaT[2][1] = 'T';
        }else if(rotacao == 180){
            cleanPeca(id);
            this->pecaT[0][1] = 'T';
            this->pecaT[1][0] = 'T';
            this->pecaT[1][1] = 'T';
            this->pecaT[1][2] = 'T';
        }else if(rotacao == 270){
            cleanPeca(id);
            this->pecaT[0][0] = 'T';
            this->pecaT[1][0] = 'T';
            this->pecaT[2][0] = 'T';
            this->pecaT[1][1] = 'T';
        }else if(rotacao == 0){
            return;
        }
    }else if(id == 'Z'){
        if(rotacao == 90 || rotacao == 270){
            cleanPeca(id);
            this->pecaZ[0][1] = 'Z';
            this->pecaZ[1][0] = 'Z';
            this->pecaZ[2][0] = 'Z';
            this->pecaZ[1][1] = 'Z';
        }else if(rotacao == 0 || rotacao == 180){
            return;
        }
    }
}


void Tetris::imprimePeca(){
    cout << "Peca I: " << "\n";
    for(int i = 0; i < 4; i ++){
        for(int j = 0; j < 4; j++){
            cout << this->pecaI[i][j];
        }
        cout << endl;
    }

    cout << "Peca J: " << "\n";
    for(int i = 0; i < 4; i ++){
        for(int j = 0; j < 4; j++){
            cout << this->pecaJ[i][j];
        }
        cout << endl;
    }

    cout << "Peca L: " << "\n";
    for(int i = 0; i < 4; i ++){
        for(int j = 0; j < 4; j++){
            cout << this->pecaL[i][j];
        }
        cout << endl;
    }

    cout << "Peca O: " << "\n";
    for(int i = 0; i < 4; i ++){
        for(int j = 0; j < 4; j++){
            cout << this->pecaO[i][j];
        }
        cout << endl;
    }

    cout << "Peca S: " << "\n";
    for(int i = 0; i < 4; i ++){
        for(int j = 0; j < 4; j++){
            cout << this->pecaS[i][j];
        }
        cout << endl;
    }

    cout << "Peca T: " << "\n";
    for(int i = 0; i < 4; i ++){
        for(int j = 0; j < 4; j++){
            cout << this->pecaT[i][j];
        }
        cout << endl;
    }

    cout << "Peca Z: " << "\n";
    for(int i = 0; i < 4; i ++){
        for(int j = 0; j < 4; j++){
            cout << this->pecaZ[i][j];
        }
        cout << endl;
    }
}

void Tetris::cleanPeca(char id){
    if(id == 'I'){
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)               
                this->pecaI[i][j] = ' ';
    }else if(id == 'J'){
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)               
                this->pecaJ[i][j] = ' ';
    }else if(id == 'L'){
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)               
                this->pecaL[i][j] = ' ';
    }else if(id == 'O'){
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)               
                this->pecaO[i][j] = ' ';
    }else if(id == 'S'){
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)               
                this->pecaS[i][j] = ' ';
    }else if(id == 'T'){
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)               
                this->pecaT[i][j] = ' ';
    }else if(id == 'Z'){
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)               
                this->pecaZ[i][j] = ' ';
    }
}



//////////////Operadores//////////////
Tetris &Tetris::operator=(const Tetris &other){
    if(this == &other)
        return *this;
    
    for(int i = 0; i < this->colunas; i++){
        delete []jogo[i];
    }
    delete []jogo;
    delete []alturas;

    for(int i = 0; i < 4; i++){
        delete []pecaI[i];
        delete []pecaJ[i];
        delete []pecaL[i];
        delete []pecaO[i];
        delete []pecaS[i];
        delete []pecaT[i];
        delete []pecaZ[i];
    }
    delete []pecaI;
    delete []pecaJ;
    delete []pecaL;
    delete []pecaO;
    delete []pecaS;
    delete []pecaT;
    delete []pecaZ;
    
    this->colunas = other.colunas;
    this->alturas = new int[this->colunas];
    this->jogo = new char*[this->colunas];

    this->pecaI = new char*[4];
    this->pecaJ = new char*[4];
    this->pecaL = new char*[4];
    this->pecaO = new char*[4];
    this->pecaS = new char*[4];
    this->pecaT = new char*[4];
    this->pecaZ = new char*[4];

    for(int i = 0; i < this->colunas; i++){
        this->jogo[i] = new char[other.alturas[i]];
        this->alturas[i] = other.alturas[i];
    }

    for(int i = 0; i < 4; i++){
        this->pecaI[i] = new char[4];
        this->pecaJ[i] = new char[4];
        this->pecaL[i] = new char[4];
        this->pecaO[i] = new char[4];
        this->pecaS[i] = new char[4];
        this->pecaT[i] = new char[4];
        this->pecaZ[i] = new char[4];
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            this->pecaI[i][j] = other.pecaI[i][j];
            this->pecaJ[i][j] = other.pecaJ[i][j];
            this->pecaL[i][j] = other.pecaL[i][j];
            this->pecaO[i][j] = other.pecaO[i][j];
            this->pecaS[i][j] = other.pecaS[i][j];
            this->pecaT[i][j] = other.pecaT[i][j];
            this->pecaZ[i][j] = other.pecaZ[i][j];
        }
    }

    for(int i = 0; i < this->colunas; i++){
        for(int j = 0; j < this->alturas[i]; j++){
            jogo[i][j] = other.jogo[i][j];
        }
    }

    return *this;
}

//////////////Destrutor//////////////
Tetris::~Tetris(){
    //deletando as pecas
    for(int i = 0; i < 4; i++){
        delete []pecaI[i];
        delete []pecaJ[i];
        delete []pecaL[i];
        delete []pecaO[i];
        delete []pecaS[i];
        delete []pecaT[i];
        delete []pecaZ[i];
    }
    delete []pecaI;
    delete []pecaJ;
    delete []pecaL;
    delete []pecaO;
    delete []pecaS;
    delete []pecaT;
    delete []pecaZ;


    for(int i = 0; i < this->colunas; i++){
        delete []jogo[i];                           //deleta os arrays do array de colunas (ou seja os arrays que representam as alturas das colunas)
    }
    delete []jogo;                                  //deleta o array de colunas
    delete []alturas;                               //deleta o array do tamanho das alturas

}