#include <iostream>

int main()
{
	long long n,k,m,answer = 0;
	std :: cin >> n >> k >> m;
	while(n > k+answer*m)
	{
		n -=(k+answer*m);
		answer++;
	}
	std :: cout << n << "\n";
}