#include <iostream>

using namespace std;

int main()
{
	short mas[100][100];
	int n,m;
	cin >> n >> m;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
		cin >> mas[i][j];
	for (int i=1; i<n; i++) mas[i][0] = mas[i-1][0]+mas[i][0];
	for (int j=1; j<m; j++) mas[0][j] = mas[0][j-1]+mas[0][j];
	for (int i=1; i<n; i++)
		for (int j=1; j<m; j++)
			mas[i][j] = mas[i-1][j]+mas[i][j-1]-mas[i-1][j-1]+mas[i][j];
	for (int i=0; i<n; i++)
	{
		cout << mas[i][0];
		for (int j=1; j<m; j++) cout << " " << mas[i][j];
		cout << "\n";
	}
}