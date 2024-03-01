#include <iostream>
using namespace std;

typedef struct box{
	int volume;
	int quant;
}box;

int main()
{
	int contAlt, contLarg, contComp; // altura larcura e comprimento do container
	int contVol, volTot; // volume do container e volume total das caixas
	int a = 0, b = 0, c = 0; // contadores para as caixas a, b e c
	
	cin >> contAlt >> contLarg >> contComp;
	contVol = contAlt*contLarg*contComp;
	
	box caixa[3];
	
	caixa[0].volume = 20; // caixa A
	caixa[0].quant = 10;
	caixa[1].volume = 3;  // caixa B
	caixa[1].quant = 20;
	caixa[2].volume = 4;  // caixa C
	caixa[2].quant = 25;
	
	volTot = 0;
	
	while((volTot + caixa[0].volume <= contVol && caixa[0].quant > 0) || (volTot + caixa[1].volume <= contVol && caixa[1].quant > 0) || (volTot + caixa[2].volume <= contVol && caixa[2].quant > 0))
	{
		if(caixa[1].quant > 0 && volTot + caixa[1].volume <= contVol){ // caixa B tem o menor volume, então vai primeiro
			b++;
			volTot += caixa[1].volume;
			caixa[1].quant--;
		}
		else if(caixa[2].quant > 0 && volTot + caixa[2].volume <= contVol){ // caixa C tem o segundo menor volume
			c++;
			volTot += caixa[2].volume;
			caixa[2].quant--;
		}
		else if(caixa[0].quant > 0 && volTot + caixa[0].volume <= contVol){ // caixa A tem o maior volume
			a++;
			volTot += caixa[0].volume;
			caixa[0].quant--;
		}
	}
	
	cout << "O volume total foi de: " << volTot << endl;
	cout << "Caixas A: " << a << endl;
	cout << "Caixas B: " << b << endl;
	cout << "Caixas C: " << c << endl;
	
	return 0;
}