#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	long long *mas = new long long[n], Suma = 0, swap;
	for (int i=0; i<n; i++) cin >> mas[i];
	for (int i=0; i<n-1; i++)
		for (int j=i+1; j<n; j++)
			if (mas[i]>mas[j])
			{
				swap = mas[i];
				mas[i] = mas[j];
				mas[j] = swap;
			}
	for (int i=0; i<n; i++)
		if (Suma < mas[i] - 1) break;
		else Suma+=mas[i];
	cout << Suma+1 << endl;
}