#include <iostream>
using namespace std;
int Suma = 0,n,k = 0, X = 0, Y = 0,m[100][100],I,J;

void right()
{
	for (int i = X; i < n; i++)
	{
		m[Y][i] = ++Suma;
		X++;
		if (i < n-1 && m[Y][i+1]) break;
	}
	Y++; X--;
}
void down()
{
	for (int i = Y; i < n; i++)
	{
		m[i][X] = ++Suma;
		Y++;
		if (i < n-1 && m[i+1][X]) break;
	}
	X--; Y--;
}
void left()
{
	for (int i = X; i >= 0; i--)
	{
		m[Y][i] = ++Suma;
		X--;
		if (i >= 1 && m[Y][i-1]) break;
	}
	Y--; X++;
}
void up()
{
	for (int i = Y; i >= 0; i--)
	{
		m[i][X] = ++Suma;
		Y--;
		if (i >= 1 && m[i-1][X]) break;
	}	
	X++; Y++;
}
int main()
{
	cin >> n >> I >> J;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) m[i][j] = 0;
	while (Suma < n*n)
	{
		switch (k%4)
		{
		case 0 : right(); k++; break;
		case 1 : down(); k++; break;
		case 2 : left(); k++; break;
		case 3 : up(); k++; break;
		}
	}
	cout << m[I-1][J-1]<<endl;
}