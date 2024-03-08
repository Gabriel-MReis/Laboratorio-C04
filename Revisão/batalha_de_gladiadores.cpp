#include <iostream> 
#include <string>
#include <cmath>

using namespace std;

struct gladiador
{
    string nome;
    int forca;
    int habilidade;
    int idade;
};

bool batalha(gladiador g1, gladiador g2)
{
    int dano_g1, dano_g2;
    int ataques_g1, ataques_g2;

    //calculando o dano de ataque de cada gladiador
    dano_g1 = g1.forca + pow(2,g1.habilidade);
    dano_g2 = g2.forca + pow(2,g2.habilidade);

    //calculando a quantidade de ataques que cada gladiador precisa acertar para derrotar o outro
    ataques_g1 = ceil(100.0/dano_g1);
    ataques_g2 = ceil(100.0/dano_g2);

    //verificando qual gladiador derrota o seu oponente primeiro
    return ataques_g1<=ataques_g2 ? true : false;
}

int main()
{
    gladiador lista_gladiadores[5];
    int gladiador1, gladiador2;
    bool resultado;

    for(int i=0; i<5; i++)
    {
        cin >> lista_gladiadores[i].nome;
        cin >> lista_gladiadores[i].forca;
        cin >> lista_gladiadores[i].habilidade;
        cin >> lista_gladiadores[i].idade;
        cin.ignore();
    }

    while(1)
    {
        cin >> gladiador1;
        if(gladiador1 == -1)
            break;

        cin >> gladiador2;
        if(gladiador2 == -1)
            break;

        resultado = batalha(lista_gladiadores[gladiador1], lista_gladiadores[gladiador2]);
    
        if(resultado)
            cout << lista_gladiadores[gladiador1].nome << " ganhou a batalha contra " << lista_gladiadores[gladiador2].nome << endl;
        else 
            cout << lista_gladiadores[gladiador2].nome << " ganhou a batalha contra " << lista_gladiadores[gladiador1].nome << endl;
    }
}