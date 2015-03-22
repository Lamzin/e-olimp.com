#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

string str;
int k, ans = 0;

int main()
{
	cin >> k >> str;
	for (int i = 0; i < str.length(); i++)
	{
		ans = (ans * 10 + (str[i] - 48)) % k;
	}

	cout << ans << endl;
}