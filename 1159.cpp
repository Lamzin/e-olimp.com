#include <iostream>
using namespace std;

int main()
{
	int Sum;
	cin >> Sum;
	for (int d = 1; d < 32; d++)
		for (int m = 1; m < 13; m++)
			if (d*12+m*31 == Sum)
			{
				if (d < 10) cout << 0;
				cout << d << "/";
				if (m < 10) cout << 0;
				cout << m << endl;
				return 0;
			}
}