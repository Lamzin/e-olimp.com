#include <iostream>
using namespace std;
#define SIZE 250

char mas[SIZE][SIZE], temp;
bool bmas[SIZE][SIZE];
int X[SIZE*SIZE], Y[SIZE*SIZE], W[SIZE*SIZE], size = 0, n, i_ver = 0;
int xsta,ysta,xfin,yfin;
bool flag = true, way = false;

void F(int A, int B)
{
	bmas[A][B] = true;
	X[size] = A;
	Y[size] = B;
	W[size] = i_ver;
	size++;
}

int main()
{
	cin >> n;
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
		{
			cin >> temp;
			if (temp == 'X') 
			{
				xfin = i;
				yfin = j;
			}
			else if (temp == '@')
			{
				xsta = i;
				ysta = j;
			}
			bmas[i][j] = false;
			mas[i][j] = temp;
		}

	X[size] = xsta;
	Y[size] = ysta;
	W[size] = -1;
	size++;
	bmas[xsta][ysta] = true;

	while (flag)
	{
		if (X[i_ver] > 0 && !bmas[X[i_ver]-1][Y[i_ver]] && mas[X[i_ver]-1][Y[i_ver]]!='O') 
				F(X[i_ver]-1, Y[i_ver]);
		if (X[i_ver] < n-1 && !bmas[X[i_ver]+1][Y[i_ver]] && mas[X[i_ver]+1][Y[i_ver]]!='O') 
				F(X[i_ver]+1, Y[i_ver]);
		if (Y[i_ver] > 0 && !bmas[X[i_ver]][Y[i_ver]-1] && mas[X[i_ver]][Y[i_ver]-1]!='O')
				F(X[i_ver], Y[i_ver]-1);
		if (Y[i_ver] < n-1 && !bmas[X[i_ver]][Y[i_ver]+1] && mas[X[i_ver]][Y[i_ver]+1]!='O') 
				F(X[i_ver], Y[i_ver]+1);

		if (X[i_ver] == xfin && Y[i_ver] == yfin)
		{
			flag = false;
			way = true;
		}
		if (i_ver >= size-1) flag = false;
		i_ver++;
	}
	if (way)
	{
		i_ver--;
		while (W[i_ver] != -1)
		{
			mas[X[i_ver]][Y[i_ver]] = '+';
			i_ver = W[i_ver];
		}
		cout << "Y" << endl;
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<n; j++) cout << mas[i][j];
			cout << endl;
		}
		
	}
	else cout << "N" << endl;
}		