#include <iostream>

int main()
{
	long long n,first = 1,second = 1, k = 2,temp, Suma = 2;
	std :: cin >> n;
	while (n - Suma >=first + second)
	{
		temp = first + second;
		first = second;
		second = temp;
		Suma += second;
		k++;
	}
	std :: cout << k << "\n";
}