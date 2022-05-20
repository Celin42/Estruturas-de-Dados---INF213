#ifndef MEDIANA_H
#define MEDIANA_H
#include "MyPriorityQueue.h"
#include <iostream>


class Mediana{
    private:
        MyPriorityQueue<int> fila1;
        MyPriorityQueue<int> fila2;


    public:
        void insere(int x);
        int getMediana();
};

#endif