#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

int a;

int main()
{
	cin >> a;

	a = (a / 1000) + (a / 100 % 10) + (a / 10 % 10) + (a % 10);

	cout << a*a << endl;
}