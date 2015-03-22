#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

#define PI 3.14159265358979323846

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

long long n, k;

int main()
{
	cin >> n >> k;

	if (n & (1 << (k-1)))
	{
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
}