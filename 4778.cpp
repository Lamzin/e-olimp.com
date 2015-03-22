#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector <pair<double, double>> vect;

double x, y, AC, AB, BC;

int main()
{
	for (int i = 0; i < 3; i++)
	{
		cin >> x >> y;
		vect.push_back(make_pair(x, y));
	}
	if (vect[0] == vect[2])
	{
		cout << "YES\nYES\nYES\n";
	}
	else if (vect[0] == vect[1])
	{
		cout << "YES\nNO\nYES\n";
	}
	else
	{
		AC = hypot(vect[0].first - vect[1].first, vect[0].second - vect[1].second);
		BC = hypot(vect[0].first - vect[2].first, vect[0].second - vect[2].second);
		AB = hypot(vect[2].first - vect[1].first, vect[2].second - vect[1].second);

		if (abs(AB + BC - AC) < 0.001 || abs(AC + BC - AB) < 0.001 || abs(AB + AC - BC) < 0.001) cout << "YES" << endl;
		else cout << "NO" << endl;

		if (abs(BC + AC - AB) < 0.001 || abs(BC + AB - AC) < 0.001) cout << "YES" << endl;
		else cout << "NO" << endl;

		if (abs(BC + AC - AB) < 0.001) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}