#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

string a, b;

int main()
{
	cin >> a >> b;

	cout << b << " " << a << endl;
}