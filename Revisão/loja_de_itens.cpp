#include <iostream>
#include <list>
#include <string>

using namespace std;

struct item
{
    int cod;
    string nome;
    int preco;
    int status;
};

int hash_aux(int k, int m){
	int h;
	h = k%m;
	if(h<0)
		h+=m;
	return h;
}

int hash(int k, int i, int m){
	return (hash_aux(k,m)+i)%m;
}

void hash_insert(item t[], int cod, string nome, int preco, int m)
{
	int i;
	int j;
	i = 0;

	while(i < m)
	{
		j = hash(cod, m, i);
		if(t[j].status == 0)
		{
			t[j].cod = cod;
            t[j].nome = nome;
            t[j].preco = preco;
			t[j].status = 1;
			return;

		}
		else i++;
	}
}

int hash_search(item t[], int cod, int m)
{
	int i;
	int j;
	i = 0;
	do
	{
		j = hash(cod, m, i);
		if(t[j].cod == cod)
			return j;
		else i++;
	}
	while(t[j].status != 0 || i < m);

	return -1;
}

int main()
{
    int n;
    int m = 43;
    item t[m];
    int cod;
    string nome;
    int preco;
    list<item> fila;
    list<item> pilha;
    int aux;
    int pos;
    int v;
    int c;
    int vt = 0;
    int vc = 0;
	
    cin >> n;

    for(int i = 0; i < m; i++)
	{
		t[i].status = 0;
	}

    for(int i=0; i < n; i++)
    {
        cin >> cod;
        cin >> nome;
        cin >> preco;
        hash_insert(t,cod,nome,preco,m);
    }

    cin >> aux;

    while (aux != -1)
    {
        pos = hash_search(t,aux,m);
        fila.push_back(t[pos]);
        cin >> aux;
    }

    cin >> aux;

    while (aux != -1)
    {
        pos = hash_search(t,aux,m);
        pilha.push_front(t[pos]);
        cin >> aux;
    }
    
    cin >> v >> c;

    aux = 0;
    while(aux < v)
    {
        vt += fila.begin()->preco;
        fila.pop_front();
        aux++;
    }

    aux = 0;
    while(aux < c)
    {
        vc += pilha.begin()->preco;
        pilha.pop_front();
        aux++;
    }

    cout << vt-vc << " moeda(s).\n";
}