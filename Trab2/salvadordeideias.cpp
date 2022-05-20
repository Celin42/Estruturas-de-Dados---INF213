void Tetris::createPeca(int id){
    if(id == 'I'){
        this->pecaI = new char*[4];
        for(int i = 0; i < 4; i++)
            this->pecaI[i] = new char[4];
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){                       
                this->pecaI[i][j] = ' ';
            }
        }
    }else if(id == 'J'){
        this->pecaJ = new char*[4];
        for(int i = 0; i < 4; i++)
            this->pecaJ[i] = new char[4];
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){                       
                this->pecaJ[i][j] = ' ';
            }
        }
    }else if(id == 'L'){
        this->pecaL = new char*[4];
        for(int i = 0; i < 4; i++)
            this->pecaL[i] = new char[4];
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){                       
                this->pecaL[i][j] = ' ';
            }
        }
    }else if(id == 'O'){
        this->pecaO = new char*[4];
        for(int i = 0; i < 4; i++)
            this->pecaO[i] = new char[4];
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){                       
                this->pecaO[i][j] = ' ';
            }
        }
    }else if(id == 'S'){
        this->pecaS = new char*[4];
        for(int i = 0; i < 4; i++)
            this->pecaS[i] = new char[4];
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){                       
                this->pecaS[i][j] = ' ';
            }
        }
    }else if(id == 'T'){
        this->pecaT = new char*[4];
        for(int i = 0; i < 4; i++)
            this->pecaT[i] = new char[4];
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){                       
                this->pecaT[i][j] = ' ';
            }
        }
    }else if(id == 'Z'){
        this->pecaZ = new char*[4];
        for(int i = 0; i < 4; i++)
            this->pecaZ[i] = new char[4];
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){                       
                this->pecaZ[i][j] = ' ';
            }
        }
    }
}

void Tetris::destroyPeca(int id){
    if(id == 'I'){
        for(int i = 0; i < 4; i++)
            delete []pecaI[i];
        delete []pecaI;

    }else if(id == 'J'){
        for(int i = 0; i < 4; i++)
            delete []pecaJ[i];
        delete []pecaJ;

    }else if(id == 'L'){
        for(int i = 0; i < 4; i++)
            delete []pecaL[i];
        delete []pecaL;

    }else if(id == 'O'){
        for(int i = 0; i < 4; i++)
            delete []pecaO[i];
        delete []pecaO;

    }else if(id == 'S'){
        for(int i = 0; i < 4; i++)
            delete []pecaS[i];
        delete []pecaS;

    }else if(id == 'T'){
        for(int i = 0; i < 4; i++)
            delete []pecaT[i];
        delete []pecaT;

    }else if(id == 'Z'){
        for(int i = 0; i < 4; i++)
            delete []pecaZ[i];
        delete []pecaZ;

    }
}



void Tetris::redimensionaAlturas(){
    int maiorAltura = getAltura();

    int *auxAlturas = new int[this->colunas];

    for(int i = 0; i < this->colunas; i++)
        auxAlturas[i] = this->alturas[i];
    

    delete []alturas;

    this->alturas = new char[this->colunas];

    
    for (int i = 0; i < this->colunas; i++){
        for(int j = 0; j < maiorAltura; i++){
            if(jogo[i][j] != ' ')
                this->alturas[i] += 1;
        }
    }

    delete []auxAlturas;
}













