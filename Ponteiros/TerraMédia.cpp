#include <iostream>
using namespace std;

int main() {
    int terras[5]; // Artefatos m�gicos em cada terra
    int* ponteiro = terras; // Ponteiro para o in�cio do vetor
    int soma = 0;
    int tamanho = sizeof(terras)/sizeof(terras[0]); // Calcula o tamanho do vetor
    
    for(int i = 0; i < tamanho; i++)
	{
		cin >> terras[i];
	}

    for(int i = 0; i < tamanho; i++) {
        cout << "Artefato coletado na terra " << i << ": " << *ponteiro << endl;
        soma += *ponteiro; // Soma o valor do artefato
        ponteiro++; // Move o ponteiro para a pr�xima posi��o
    }

    cout << "Fim da jornada! Soma total dos artefatos: " << soma << endl;

    return 0;
}
