#include <iostream>
#include <vector>
#include <algorithm>

#include <math.h>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int amin, amax = min(a, b);
	amin = (max(a, b) % 2) ? ((max(a, b) + 1) / 2) : (max(a, b) / 2);
	cout << amin << " " << amax << endl;

	return 0;
}