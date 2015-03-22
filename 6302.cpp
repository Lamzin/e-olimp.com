#include <iostream>
#include <vector>

using namespace std;

vector <int> vect;

unsigned long long n, NOK = 0;

unsigned long long NOD(unsigned long long a, unsigned long long b)
{
	if (b == 0)
		return a;
	else
		return NOD(b, a % b);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		static int tmp;
		cin >> tmp;
		vect.push_back(tmp);
	}

	NOK = vect[0] * vect[1] / NOD(vect[0], vect[1]);
	for (int i = 2; i < n; i++)
		NOK = NOK * vect[i] / NOD(NOK, vect[i]);
	cout << NOK << endl;
}