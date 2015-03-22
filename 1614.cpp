#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

#define PI 3.14159265358979323846

vector <pair <double, double>> point;
vector <double> side;
float x, y;

int main()
{
	for (int i = 0; i < 3; i++)
	{
		cin >> x >> y;
		point.push_back(make_pair(x,y));
	}

	side.push_back(hypot(point[0].first - point[1].first, point[0].second- point[1].second));
	side.push_back(hypot(point[0].first - point[2].first, point[0].second - point[2].second));
	side.push_back(hypot(point[2].first - point[1].first, point[2].second - point[1].second));

	sort(side.begin(), side.end());

	cout.precision(6);
	cout << fixed << acos((pow(side[2], 2) - pow(side[1], 2) - pow(side[0], 2)) / (-2 * side[0] * side[1]))  * 180 / PI << endl;
}