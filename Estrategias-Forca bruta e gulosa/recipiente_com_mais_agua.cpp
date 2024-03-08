#include<iostream>

using namespace std;

int main()
{
    int n;
    int array[100];
    int area;
    int altura;
    int comprimento;
    int maior_area = 0;

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> array[i];
    }

    for(int i = 1; i < n; i++)
    {
        for(int j = i+1; j <= n; j++)
        {
            if(array[i] < array[j])
                altura = array[i];
            else 
                altura = array[j];

            comprimento = j - i;

            area = altura*comprimento;

            if(area > maior_area)
                maior_area = area;

        }
    }

    cout << maior_area << endl;

    return 0;
}