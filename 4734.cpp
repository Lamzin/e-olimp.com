#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

string str;
int Sum = 0;

int main()
{
	cin >> str;
	for (int i = 0; i < str.length(); i++)
		Sum += (str[i] - 48);
	if (Sum % 3) cout << "No\n"; else cout << "Yes\n";
	if (Sum % 3 == 0 && str[str.length()-1] % 2 == 0) cout << "Yes\n"; else cout << "No\n";
	if (Sum % 9) cout << "No\n"; else cout << "Yes\n";
}