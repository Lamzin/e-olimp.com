#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector <pair<double, double>> vect;

double x, y;
int answer = 0;

bool check(pair<double, double> a, pair<double, double> b, pair<double, double> c)
{
	double A, B, C;
	A = hypot(a.first - b.first, a.second - b.second);
	B = hypot(a.first - c.first, a.second - c.second);
	C = hypot(c.first - b.first, c.second - b.second);

	if (abs(A*A + C*C - B*B) < 0.001) return true;
	else return false;
}

int main()
{
	for (int i = 0; i < 4; i++)
	{
		cin >> x >> y;
		vect.push_back(make_pair(x, y));
	}
	if (check(vect[0], vect[1], vect[2])) answer++;
	if (check(vect[1], vect[2], vect[3])) answer++;
	if (check(vect[2], vect[3], vect[0])) answer++;
	if (check(vect[3], vect[0], vect[1])) answer++;

	cout << answer << endl;
}