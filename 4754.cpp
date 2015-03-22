#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

long long n, ans = 0, k, param = 1;
string str;

int main()
{
	cin >> k >> str;
	for (int i = str.length() - 1; i >= 0; i--)
	{
		ans += (str[i] - 48) * param;
		param *= k;//	pow(k, str.length() - i - 1);
	}
	cout << ans << endl;
}