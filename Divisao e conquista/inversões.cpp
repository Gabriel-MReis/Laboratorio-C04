#include <iostream>
using namespace std;

// primeiro subvetor entre p e q-1, segundo subvetor entre q e r-1
unsigned long long mergeCounting(int v[], int p, int q, int r){
	int i, j, k, tam;
	unsigned long long num_inv = 0;
	i = p;
	j = q;
	k = 0;
	tam = r - p;
	int w[100];
	while(i < q && j < r){
		if(v[i] <= v[j])
			w[k++] = v[i++];
		else { // v[i] > v[j]
			w[k++] = v[j++];
			num_inv += q - i;
		}
	}
	while(i < q) w[k++] = v[i++];
	while(j < r) w[k++] = v[j++];
	for(k = 0; k < tam; k++){
		v[p + k] = w[k];
	}
	return num_inv;
}

unsigned long long countInversionsR(int v[], int p, int r){
	int m; // meio do vetor
	unsigned long long num_inv = 0;
	if (r - p > 1){
		m = (p + r) / 2;
		num_inv += countInversionsR(v, p, m);
		num_inv += countInversionsR(v, m, r);
		num_inv += mergeCounting(v, p, m, r);
	}
	return num_inv;
}

int main()
{
	int v[100];
	int n;
	
	cin >> n;

	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	
	cout << countInversionsR(v, 0, n) << endl;
	
	return 0;
}