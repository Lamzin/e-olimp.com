#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

int a,b;

int main()
{
	cin >> a;
	b = (a % 10) * 100 + (a / 10 % 10) * 10 + a / 100;

	cout << b << endl;
}