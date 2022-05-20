



void merge(int *v, int p, int q, int r, int *aux){
    int tam = r-p;
    int i = p;//cursor 1
    int j = q;//cursor 2
    int k = 0;//cursor aux

    while(i < q && j < r){
        if(v[i] <= v[j]){
            aux[k] = v[i];
            i++;
            k++;
        }
        else{
            aux[k] = v[j];
            j++;
            k++;
        }
    }

    while(i < q){
        aux[k] = v[i];
        i++;
        k++;
    }
    while(j < r){
        aux[k] = v[j];
        j++;
        k++;
    }

    for(k = 0; k < tam; k++){
        v[p+k] = aux[k];
    }


}


void mergesort(int *v, int p, int r, int *aux){
    if(p < r-1){
        int meio = (p+r)/2;
        mergesort(v, p, meio, aux);
        mergesort(v, meio, r, aux);
        merge(v, p , meio, r, aux);
    }
}



void mergesort(int *v, int n){
    int *aux = new int[n];
    mergesort(v, 0, n, aux);
}