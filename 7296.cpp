#include <iostream>
#include <vector>
#include <algorithm>

#include <math.h>

using namespace std;

int n, mas[12];
bool ans[100];

int main()
{
	cin >> n;

	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i<12; i++)
		{
			cin >> mas[i];
		}
		sort(mas, mas + 12);
		ans[j] = mas[0] == mas[1] && mas[1] == mas[2] && mas[2] == mas[3] &&
			mas[4] == mas[5] && mas[5] == mas[6] && mas[6] == mas[7] &&
			mas[8] == mas[9] && mas[9] == mas[10] && mas[10] == mas[11];

	}

	for (int i = 0; i < n; i++)
	if (ans[i])
		cout << "yes\n";
	else
		cout << "no\n";

	return 0;
}