#include <iostream>
using namespace std;
int Suma = 0,n,k = 0, X = 0, Y = 0,new_sum;
bool m[50][50];

void right()
{
	X--;
	for (int i = X+1; i < n; i++)
	{
		m[Y][i] = true;
		X++;
		Suma++;
		if (i < n-2 && m[Y][i+2]) break;
	}
}
void down()
{
	Y--;
	for (int i = Y+1; i < n; i++)
	{
		m[i][X] = true;
		Y++;
		Suma++;
		if (i < n-2 && m[i+2][X]) break;
	}
}
void left()
{
	X++;
	for (int i = X-1; i >= 0; i--)
	{
		m[Y][i] = true;
		X--;
		Suma++;
		if (i >= 2 && m[Y][i-2]) break;
		}
}
void up()
{
	Y++;
	for (int i = Y-1; i >= 0; i--)
	{
		m[i][X] = true;
		Y--;
		Suma++;
		if (i >= 2 && m[i-2][X]) break;
	}	
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) m [i][j] = false;
	do
	{
		new_sum = Suma;
		switch (k%4)
		{
		case 0 : right(); k++; break;
		case 1 : down(); k++; break;
		case 2 : left(); k++; break;
		case 3 : up(); k++; break;
		}
	}
	while (k != n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		if (n % 4 == 3)
		{
			if (m[i][j]) cout << 1; else cout << 0;
		}
		else 
		{
			if (m[i][j]) cout << 0; else cout << 1;
		}
		cout << endl;
	}
}