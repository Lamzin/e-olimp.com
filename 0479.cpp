#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int n, tmp, mas[100];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> mas[i];
	for (int i = 0; i < n; i++)
	{
		tmp = mas[i];
		for (int j = 0; j < tmp; j++)
		{
			for (int g = 0; g < tmp; g++)
			{
				if (j == g || tmp-1-j == g) cout << "X";
				else cout << " ";
			}
			if (i != n-1 || j!=tmp -1) cout << endl;
		}
		if (i != n-1) cout << endl;
	}
	cout << endl;
}