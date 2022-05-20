#include <algorithm>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

//Vamos usar variaveis globais nesse caso...
//Isso nao é uma boa pratica, mas vai facilitar no seu entendimento/implementacao da busca binaria
int taxaVideo,taxaDownload,tamanho;

typedef void (consigoAssistirSemPausas)(int tempoCarregamento);

//Essa funcao devera retornar true sse for possível 
//assistir a um vídeo de "tamanho" segundos, que gasta taxaVideo bytes por segundo para ser assistido
//supondo que sua internet consegue baixar taxaDownload bytes por segundo.
//tempoCarregamento indica quanto tempo voce irá aguardar para começar assistir ao vídeo
//Implemente esta funcao

bool consigoAssistirSemPausas(int tempoCarregamento) {
	int dadosBaixados = taxaDownload * tempoCarregamento;

	for(int i = 0; i < tamanho; i++){
		dadosBaixados = dadosBaixados - taxaVideo + taxaDownload;
	}

	if(dadosBaixados >= 0)
		return true;
	else
		return false;
}


int buscaSeq(bool *array,int begin,int end, int chave) {
	for(int i=begin;i<=end;i++)
		if (array[i] >= chave)
			return i;

	return -1;
}

int buscaBin(int *array,int begin, int end, int chave) {

	int meio = (end-begin)/2 + begin;

	if(begin > end){
		if(array[meio] > chave)
			return meio;
		else
			return -1;
	}

	if (array[meio] == chave){
		while(array[meio-1] == chave)
			meio--;
		return meio;
	}

	if (array[meio] > chave)
		return buscaBin(array,begin, meio-1, chave);
	return buscaBin(array,meio+1, end, chave);
}




int main() {

	bool *resultado = new bool[5000];

	cin >> taxaVideo >> taxaDownload >> tamanho;
	for(int i = 0; i < 5000; i++) {
		resultado[i] = consigoAssistirSemPausas(i);
	}

	cout << buscaBin(resultado, 0, 5000, 1) << endl;

	delete[] resultado;
	return 0;


}