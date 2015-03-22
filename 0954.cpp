#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

#define PI 3.14159265358979323846

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

double a, b, H;

int main()
{
	cin >> a >> b >> H;
	cout.precision(2);
	cout << fixed << 2 * (a+b) * hypot(a / 2 - b / 2, H)<< endl;
}