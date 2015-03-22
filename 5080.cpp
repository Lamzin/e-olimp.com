#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

#define PI 3.14159265358979323846

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

int n, tmp, ans = 0;
bool k;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		tmp = 0;
		for (int j = 0; j < n; j++)
		{
			cin >> k;
			if (k) tmp++;
		}
		if (tmp == 1) ans++;
	}
		
	cout << ans << endl;
}