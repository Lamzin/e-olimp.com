#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

int n, ans = 0, tmp;

int main()
{
	cin >> n;
	for (int i = 0; i < n*n; i++)
	{
		cin >> tmp;
		ans += tmp;
	}
	cout << ans / 2 << endl;
}