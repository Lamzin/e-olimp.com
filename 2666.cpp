#include <iostream>
using namespace std;

int main()
{
	int n,X,Y;
	cin >> n;
	X = n; Y = 1;
	for (int i = 1; i<=n; i++, X--, Y++, cout << endl)
		for (int j = 1; j<=n; j++)
		{
			if (i <= Y && j < X) cout << 2;
			else if (i >= Y && j > X) cout << 1;
			else cout << 0;
		}
}