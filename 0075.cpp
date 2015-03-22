#include <iostream>

using namespace std;

int main()
{
	int a,m,n = 0;
	cin >> a >> m;
	while (m)
	{
		n++;
		if (m == a*2) break;
		m-=a;
		a++;
	}
	cout << n << endl;
}