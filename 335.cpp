#include <iostream>

using namespace std;
int main()
{
	bool mas[10];
	long n,temp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		mas[i] = false;
		for (int j = 1; j<=temp; j++)
			if (temp % j == 0)
				if (mas[i]) mas[i] = false;
				else mas[i] = true;
	}
	for (int i = 0; i<n; i++)
		if (mas[i]) cout << "1\n";
		else cout << "0\n";
}