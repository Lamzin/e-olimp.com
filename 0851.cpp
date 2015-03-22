#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

vector <pair<long long, long long>> vect;
int n;
long long x, y;
double ans = 0;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		vect.push_back(make_pair(x,y));
	}
	
	for (int i = 0; i < n-1; i++)
		ans += (vect[i].first - vect[i + 1].first) * (vect[i].second + vect[i + 1].second) / 2.0f;
	ans += (vect[n-1].first - vect[0].first) * (vect[0].second + vect[n-1].second) / 2.0f;
	ans = abs(ans);

	cout.precision(1);
	cout << fixed << ans << endl;
}