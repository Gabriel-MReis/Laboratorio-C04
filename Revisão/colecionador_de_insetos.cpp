#include <iostream>
#include <string>
using namespace std;

struct Inseto {
    string nome;
    double tamanho;
};

void bubbleSort(Inseto insetos[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (insetos[j].tamanho > insetos[j + 1].tamanho) {
                Inseto temp = insetos[j];
                insetos[j] = insetos[j + 1];
                insetos[j + 1] = temp;
            }
        }
    }
}

int main() {
    int quantidade;
    Inseto insetos[1000];
    cin >> quantidade;

    for (int i = 0; i < quantidade; i++) {
        cin.ignore();
        getline(cin, insetos[i].nome);
        cin >> insetos[i].tamanho;
    }

    bubbleSort(insetos, quantidade);

    for (int i = 0; i < quantidade; i++) {
        cout << insetos[i].nome << endl;
    }

    return 0;
}
