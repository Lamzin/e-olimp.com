#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector <pair<float, float>> vect;

float x, y;

int main()
{
	for (int i = 0; i < 4; i++)
	{
		cin >> x >> y;
		vect.push_back(make_pair(x, y));
	}
	cout.precision(3);
	cout << fixed << (vect[0].first + vect[2].first) / 2 << " " << (vect[0].second + vect[2].second) / 2 << endl << hypot(vect[0].first - vect[2].first, vect[0].second - vect[2].second) << " " << hypot(vect[1].first - vect[3].first, vect[1].second - vect[3].second) << endl;
}