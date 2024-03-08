#include <iostream>
using namespace std;

int main()
{
	int M;
	int x, y, area;
	int maior = 0, xi, yi;
	
	cin >> M;
	
	x = 2;
	
	y = M - 2;
	
	while(x < M){
		area = (x/2)*y;
		if(area >= maior){
			xi = x/2;
			yi = y;
			maior = area;
		}
		x += 2;
		y = M - x;
	}
	
	cout << xi << " x " << yi << endl;
	
	return 0;
}