#include <algorithm>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <cassert>
using namespace std;


/* Supondo que v[p...q-1] e 
v[q...r-1] estejam ordenados */
void merge(int *v, int p, int q, int r) {
    int i = p; //cursor 1
    int j = q; //cursor 2
    int k = 0; //cursor para aux
    int n1 = q-p+1; //tamanho do vetor esquerdo
    int n2 = r-q; //tamanho do vetor direito
    int leftBucket[n1];
    int rightBucket[n2];

    for (i = 0; i < n1; i++)
        leftBucket[i] = v[p + i];

    for (j = 0; j < n2; j++)
        rightBucket[j] = v[q + 1+ j];

    
    while(i < n1 && j < n2) {
        if (leftBucket[i] <= rightBucket[j])
            v[k++] = leftBucket[i++];
        else
            v[k++] = rightBucket[j++];
    }
    while(i < n1)
        v[k++] = leftBucket[i++];
    while(j < r)
        v[k++] = rightBucket[j++];

}

void mergeSort(int *v, int n) {
    int k; // tamanho dos buckets a cada chamada
    int pont; //identificação do primeiro elemento do subarray a esquerda

    for(k = 1; k < n; k*=2){
        for(pont = 0; pont < n-1; pont += 2*k){
            if((pont+k-1) < n-1)
                int meio = pont+k-1;
            else
                int meio = n-1;
            
            if((pont+2*k-1) < n-1)
                int r = pont+2*k-1;
            else
                int r = n-1;
            
            merge(v, pont, meio, r);
        }

    }
}

//nao modifique nada daqui para baixo...

int main(int argc, char**argv) {
	//sem srand, para sempre usarmos a mesma semente...
	int n;
	cin >> n;
	int *v = new int[n];

	for(int i=0;i<n;i++) cin >> v[i];

	int soma = 0;

	//Mede o tempo de 10000 execucoes em microsegundos
	auto t0 = std::chrono::system_clock::now();
	mergeSort(v,n);
	auto tempoSort = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - t0);
	cerr << "Tempo para ordenar (us): " << tempoSort.count() << "\n";

	for(int i=0;i<n-1;i++) assert(v[i]<=v[i+1]);
	cout << "ok\n";

	delete []v;
	return 0;
}