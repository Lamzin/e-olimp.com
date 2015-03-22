#include <iostream>

using namespace std;

int main()
{
	int n, m, k, d;
	cin >> m >> n >> k;
	cout << m/n << ".";
	d = m % n;
	for (int i = 0; i < k; i++)
	{
		d *= 10;
		cout << d/n;
		d %= n;
	}
	cout << endl;
}