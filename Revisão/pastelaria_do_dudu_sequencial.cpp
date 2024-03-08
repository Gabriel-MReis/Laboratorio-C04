#include <iostream>
#include <string>

using namespace std;

struct Produto {
    string nome;
    int quantidade;
};

int main() {
    int N;
    Produto produtos[1000];
    string busca;

    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> produtos[i].nome >> produtos[i].quantidade;
    }

    cin >> busca;

    bool encontrado = false;
    for (int i = 0; i < N; i++) {
        if (produtos[i].nome == busca) {
            encontrado = true;
            break;
        }
    }

    if (encontrado) {
        cout << busca << " em estoque!" << endl;
    } else {
        cout << "Nao existe " << busca << " em estoque!" << endl;
    }

    return 0;
}