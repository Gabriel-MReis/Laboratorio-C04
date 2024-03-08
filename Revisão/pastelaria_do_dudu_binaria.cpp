#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Produto {
    int codigo;
    string nome;
    int quantidade;
};

int buscaBinaria(Produto produtos[], int inicio, int fim, int busca) {
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (produtos[meio].codigo == busca) {
            return meio;
        }
        if (produtos[meio].codigo < busca) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

int main() {
    int N;
    Produto produtos[1000];
    int busca;

    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> produtos[i].codigo >> produtos[i].nome >> produtos[i].quantidade;
    }

    cin >> busca;

    int indice = buscaBinaria(produtos, 0, N - 1, busca);

    if (indice != -1) {
        cout << produtos[indice].nome << " em estoque!" << endl;
    } else {
        cout << "Nao existem produtos com esse codigo em estoque!" << endl;
    }

    return 0;
}
