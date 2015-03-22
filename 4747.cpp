#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

int n, power;

int main()
{
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		if (n % i == 0)
		{
			power = 0;
			while (n % i == 0)
			{
				power++;
				n /= i;
			}
			cout << i << " " << power << endl;
		}
	}
}