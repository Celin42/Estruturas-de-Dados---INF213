#include <iostream>
#include "Mediana.h"
#include "MyStack.h"
#include "MyQueue.h"
#include "MedianaLenta.h"
#include "MyPriorityQueue.h"


void Mediana::insere(int x){
    if(fila1.size() == 0){
        fila1.push(x);
    }else if(fila1.size() == 1 && fila2.size() == 0){
        if (x > fila1.top()){
            fila2.push(-x);
        }else{
            fila2.push(-fila1.top());
            fila1.pop();
            fila1.push(x);
        }
    }else{
        if(x < fila1.top()){
            fila1.push(x);
        }else{
            fila2.push(-x);
        }
    }
 
    if(fila1.size() - fila2.size() > 1){
        fila2.push(-fila1.top());
        fila1.pop();
    }else if(fila2.size() - fila1.size() > 1){
            fila1.push(-fila2.top());
            fila2.pop();
    }
}

int Mediana::getMediana(){
    if(fila1.size() == fila2.size()){
         return ((fila1.top() - fila2.top())/2);
    }else if(fila1.size() > fila2.size()){ 
        return fila1.top();
    }else{
        return -fila2.top();
    }
}