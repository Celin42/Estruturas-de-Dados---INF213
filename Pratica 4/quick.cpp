



int particiona(int *v, int beg, int end, int pivo){
    int valoPivo = v[pivo];
    swap(v[end-1], v[pivo]);

    int pos = beg;
    for(int i = beg; i < end-1; i++){
        if(v[i] < valoPivo){
            swap(v[pos], v[i]);
            pos++;
        }
    }

    swap(v[pos], v[end-1]);

    return pos;
}



void quick(int *v, int beg, int end){
    
    if(beg == end)
        return;

    int pos = particiona(v, beg, end, beg);
    quick(v, beg, pos);
    quick(v, pos+1, end);
}

void quicksort(int *v, int n){
    quick(v, 0, n);
}