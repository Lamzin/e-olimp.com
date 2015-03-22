#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long a,b,c,d;

int main()
{
	cin >> a >> b >> c >> d;
	if ((a*b*c*d) % (a*b*c - a*b - a*c - b*c) == 0)
		cout << (a*b*c*d) / (a*b*c - a*b - a*c - b*c) << endl;
	else cout << "-1" << endl;

}