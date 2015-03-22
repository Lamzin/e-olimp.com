#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

long long a,b;

int main()
{
	cin >> a >> b;
	cout << (36 * a + b / 16) % 32 << endl;
}