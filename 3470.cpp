#include <iostream>

using namespace std;

int main()
{
	unsigned long long n,m;
	long tempx, tempy;
	cin >> n >> m;
	for (int i = 0; i < m ; i++)
		cin >> tempx >> tempy;
	if (n*n-n <= 2*m) cout << "YES" << endl;
	else cout << "NO" << endl;
}