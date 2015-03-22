#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

#define PI 3.14159265358979323846

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

double R, r, H;

int main()
{
	cin >> R >> r >> H;
	cout.precision(2);

	cout << fixed << PI*R*R + PI*r*r + (hypot(H,R-r))*(R+r)*PI << endl;
}