#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector <pair<double, double>> vect;

double x, y, A, B, C;
int answer = 0;

int main()
{
	for (int i = 0; i < 3; i++)
	{
		cin >> x >> y;
		vect.push_back(make_pair(x, y));
	}
	
	A = hypot(vect[0].first - vect[1].first, vect[0].second - vect[1].second);
	B = hypot(vect[0].first - vect[2].first, vect[0].second - vect[2].second);
	C = hypot(vect[2].first - vect[1].first, vect[2].second - vect[1].second);

	if (abs(A + B - C) < 0.001) answer = 1;

	cout << answer << endl;
}