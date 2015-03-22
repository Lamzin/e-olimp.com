#include <iostream>

using namespace std;

inline bool coprime(short x, short y)
{
	bool simple = true;
	for (int i = 2; i<=x; i++)
		if (y % i == 0 && x % i == 0) simple = false;
	return simple;
}
int main()
{
	int n,len = 0;
	short x[10000],y[10000],temp;
	cin >> n;
	for (int i=2; i<=n; i++)
		for (int j=1; j<i; j++)
		if (coprime(j,i)) 
		{
			x[len] = j;
			y[len] = i;
			len++;
		}
	for (int i=0; i<len-1;i++)
		for (int j=i+1; j<len; j++)
			if (x[i]*y[j] > x[j]*y[i])
			{
				temp = x[i];
				x[i] = x[j];
				x[j] = temp;
				temp = y[i];
				y[i] = y[j];
				y[j] = temp;
			}
	cout << "0/1\n";
	for (int i=0; i<len; i++)
		cout << x[i] << "/" << y[i] << "\n";
	cout << "1/1\n";
}