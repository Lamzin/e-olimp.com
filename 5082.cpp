#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

#define PI 3.14159265358979323846

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

long long n;
string a, b;

int main()
{
	cin >> n >> a >> b;

	for (int i = 0; i < n; i++)
	{
		if (a[i] + b[i] == 97) cout << "1";
		else cout << "0";
	}
	cout << endl;
}