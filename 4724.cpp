#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

string str;

int main()
{
	cin >> str;
	
	cout << str[2] << endl;
	cout << str [str.length()-2] << endl;
	cout << str[0] << str[1] << str[2] << str[3] << str[4] << endl;
	for (int i = 0; i < str.length() - 2; i++) cout << str[i];
	cout << endl;
	for (int i = 0; i < str.length(); i += 2) cout << str[i];
	cout << endl;
	for (int i = 1; i < str.length(); i += 2) cout << str[i];
	cout << endl;
	for (int i = str.length()-1; i >=0; i--) cout << str[i];
	cout << endl;
	for (int i = str.length() - 1; i >= 0; i-=2) cout << str[i];
	cout << endl;
	cout << str.length() << endl;
}