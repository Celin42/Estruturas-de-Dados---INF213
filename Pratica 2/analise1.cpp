
//Exemplo de analise de complexidade:
//Note que simplificamos ao máximo na notacao O (removendo o n, ja que O(n^2 +n) = O(n^2), pois a parte quadratica "pesa mais")

//Complexidade: O(n² + m + n) = O(n² + m)
void funcao1(int n, int m) {
	for(int i=0;i<n;i++) 
		for(int j=0;j<n;j++)
			ct *= j;
	
	for(int k=0;k<m;k++)
		ct += 10;

	for(int k=0;k<n;k++)
		ct += 10;
}


//Complexidade: O(n³ + n² + m) = O(n³ + m)
void funcao2(int n, int m) {
	for(int i=0;i<n;i++) 
		for(int j=0;j<n;j++)// n²
			ct *= j;
	
	for(int k=0;k<m;k++) // m
		funcao1(30,40);

	for(int k=0;k<n;k++) // n³
		funcao1(n,200);
}

//Complexidade: O(nk + m) DUVIDA
void funcao3(int n, int m, int k) {
	for(int i=0;i<n;i++) 
		for(int j=0;j<k;j++)//nk
			ct *= m;

	for(int i=0;i<m/100000;i++) {
		ct += k;
	}
}

//Complexidade: O(n²)
void funcao4(int n, int m, int k, int v[]) {
	int ct = 0;
	for(int i=0;i<n;i++) {
		if(v[i]%2==0) break;
		for(int j=0;j<n;j++) {
			ct += v[i] + v[j];
		}
	}
}

//Complexidade: O(n²)
void funcao5(int n, int m, int k, int v[]) {
	int ct = 0;
	for(int i=0;i<n;i++) {		
		for(int j=0;j<n;j++) {
			ct++;
			if(ct%2==0) break;
		}
	}
}

//Complexidade: O(n²)
void funcao6(int n, int m, int k, int v[]) {
	int ct = 0;
	for(int i=0;i<n;i++) {		
		for(int j=0;j<n;j++) {
			ct+= log(n);
		}
	}
}

//Complexidade: O(n²)
void funcao7(int n, int m, int k, int v[]) {
	int ct = 0;
	for(int i=1;i<n;i++) {		
		for(int j=i;j<n;j++) {
			ct+= log(n);
		}
	}
}

//Complexidade: O(n)
void funcao8(int n, int m, int k, int v[]) {
	int ct = 0;
	for(int i=0;i<n;i++) {		
		for(int j=0;j<log(m);j++) {
			ct += sin(k);
		}
	}
}

//Responda (alem de analisar a complexidade): o que essa funcao faz?
//Complexidade: O(log n)
//Essa funcao calcula o log na base 10
void funcao9(int n) {
	if(n==0) return 0;
	return funcao9(n/10)+1;
}

//Complexidade: O(log(n) + log(m))
void funcao10(int n, int m, int k, int v[]) {
	if(n==0 && m==0) return 1;
	if(n==0) return funcao10(n,m/2,k,v);
	else return funcao10(n/2,m,k,v);
}

//Complexidade: O(n*sum)
//Onde sum = soma dos elementos nao negativos do vetor v
void funcao11(int n, int m, int k, int v[]) {
	int ct = 0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<v[i];j++) {
			ct += k;
		}
	}
}

//Complexidade: O(n³)
int funcao12(int n) {
    int ans = 0;
    for(int i=5;i<n;i++) 
		for(int j=3;j<n;j++) 
	          for(int k=1;k<n;k++) {
	             ans += 2;
	             if(ans%10==0) break;
	          }
     return ans;
}

//Complexidade: O(ufv)
double funcao13(int v,int u, int f) {
	double ans = 0;
	for(int i=0;i<u;i++) {
	   for(int j=0;j<v;j++) ans -= log(i*j);
	   ans += log(u+i);
	   for(int j2=0;j2<f/2;j2++)
	   	for(int k=v/2;k<v;k++) //v/2
	   		ans += log(j2*k); 
	}
	return ans;
}


//Analise a complexidade de melhor e pior caso dessa função
//Diga não apenas a complexidade, mas também explique quando esses tempos ocorrem

//Melhor caso: Vai acontecer caso o m seja o primeiro elemento do vetor, tendo uma complexidade O(1)
//Pior caso: Vai acontecer caso o m nao seja um elemento do vetor, tendo uma compĺexidade O(n)

void funcao14(int n, int m, int k, int v[]) {
	int ct = 0;
	for(int i=0;i<n;i++) {
		if(v[i]==m)
			return i;		
	}
	return -1;
}

//Analise a complexidade de melhor e pior caso dessa função
//Diga não apenas a complexidade, mas também explique quando esses tempos ocorrem

//Melhor caso: Vai acontecer caso n <= 5, tendo uma complexidade O(1)
//Pior caso: Vai acontecer para valores significantes de n, tendo uma complexidade O(n³)

int funcao15(int n, int w) {
    int ans = w;
    for(int i=5;i<n;i++) 
		for(int j=3;j<n;j++) 
	          for(int k=1;k<n;k++) {
	             ans += 2;
	             if(ans%10==0) break;
	          }
     return ans;
}

//Complexidade:O(n*m)
int funcao16(int n, int w) {
    double ans = w;
    for(int i=0;i<n;i++) 
    	for(int j=0;j<n;n--) 
    		for(int k=0;k<m;k++)
    			ans += 3.14;
    	
    
    return ans;
}