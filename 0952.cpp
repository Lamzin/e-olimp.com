#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

#define PI 3.14159265358979323846

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

double a, H;

int main()
{
	cin >> a >> H;
	cout.precision(1);
	cout << fixed << a*a + 2 * a * hypot(a/2, H) << endl;
}