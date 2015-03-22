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

	a = (a / 100) + (a / 10 % 10) + (a % 10);

	cout.precision(3);
	cout << fixed << sqrtf(a) << endl;
}