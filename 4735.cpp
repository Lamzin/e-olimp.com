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
	if (str[str.length() - 1] == '5')
		cout << "Yes\nNo\n";
	else if (str[str.length() - 1] == '0')
		cout << "Yes\nYes\n";
	else cout << "No\nNo\n";
}