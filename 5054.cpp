#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

#define PI 3.14159265358979323846

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

int n;

int main()
{
	cin >> n;

	if (!(n % 4) && n % 100 || !(n % 400))
	{
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
}