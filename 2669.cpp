#include <iostream>

using namespace std;

int main()
{
	int n,m, mas[50][50];
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> mas[i][j];
	cout << m << " " << n << endl;
	for (int i = 0; i < m; i++)
	{
		cout << mas[n-1][i];
		for (int j = n-2; j >=0; j--)
			cout << " " << mas[j][i];
		cout << endl;
	}
}