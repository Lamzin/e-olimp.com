#include <iostream>

int main()
{
	long n,k=0;
	std :: cin >> n;
	while (n-1)
	{
		if (n%2) n++;
		else n/=2;
		k++;
	}
	std :: cout << k << "\n";
}