#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (i % 2)
		{
			cout << (i-1)*n+1;
			for (int j = (i-1)*n+2; j<=i*n; j++) cout << " " << j;
		}
		else 
		{
			cout << i*n;
			for (int j = i*n-1; j>=(i-1)*n+1; j--) cout << " " << j;
		}
		cout << endl;
	}
}