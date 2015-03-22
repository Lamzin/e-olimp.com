#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

string str;
int ans = 0;

int main()
{
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	if (str[i] == '5') ans++;
	cout << ans << endl;
}