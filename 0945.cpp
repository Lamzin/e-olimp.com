#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

long long a;

int main()
{
	cin >> a;

	cout << a / 100 << a % 10  << endl;
}