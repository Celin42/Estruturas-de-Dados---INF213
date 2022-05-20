#include <iostream>
#include "MyStack.h"
#include "MyQueue.h"
#include "MyPriorityQueue.h"
using namespace std;


//Voce pode adicionar includes como o abaixo...
//#include "MyStack.h"


void etapa1(){
	MyStack<int> pilha;
	MyQueue<int> fila;
	int x = 0;

	for(int i = 0; i < 6; i++){
		cin >> x;
		pilha.push(x);
		fila.push(x);
	}

	for(int i = 0; i < 6; i++){
		cout << pilha.top() << " ";
		pilha.pop();
	}
	cout << endl;

	for(int i=0;i < 6;i++){
		cout << fila.front() << " ";
		fila.pop();
	}
	cout << endl;

}

//---------------------------------------

bool verifica(){
	MyStack<char> pilha;

	pilha.push('x');
	char c;

	while(cin >> c){
		switch(c){
			case '(':
			case '[':
			case '{':
				pilha.push(c);
				break;
			
			case ')':
				if(pilha.top() != '('){
					return false;
				}else
					pilha.pop();
				break;
			case ']':
				if(pilha.top() != '['){
					return false;
				}else
					pilha.pop();
				break;
			case '}':
				if(pilha.top() != '{'){
					return false;
				}else
					pilha.pop();
				break;
		}
	}

	return pilha.top() == 'x';
}

void etapa2(){
	if(verifica()){
		cout << "Consistente" << "\n";
	}else
		cout << "Inconsistente" << "\n";
}

//---------------------------------------

//#include "MedianaLenta.h" //use essa implementacao para fazer os primeiros testes (com o calculo lento da mediana...)
#include "Mediana.h" //descomente esta linha para utilizar sua classe mais eficiente!
void etapa3() {
	Mediana mediana;

	int n,elem;	
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> elem;
		mediana.insere(elem);
		cout << mediana.getMediana() << " ";
	}
	cout << endl;
}

//---------------------------------------

int main() {
	int etapa;
	cin >> etapa;
	switch(etapa) {
		case 1:
			cout << "Etapa 1" << endl;
			etapa1();
			break;
		case 2:
			cout << "Etapa 2" << endl;
			etapa2();
			break;
		case 3:
			cout << "Etapa 3" << endl;
			etapa3();
			break;
	}
}