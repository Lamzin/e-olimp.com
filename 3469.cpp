#include <iostream>

using namespace std;

int main()
{
	short x[50000],y[50000];
	long long n;
	float k;
	cin >> n;
	for (int i = 0; i<n; i++) cin >> x[i] >> y[i];
	cout.precision(2);
	if (x[0] % 2 && y[0] % 2) k = x[0]*y[0]+0.41;
	else k = x[0]*y[0];
	cout << fixed <<"Scenario #" << 1 << ":\n" << k << "\n";
	for (int i = 1; i<n; i++)
	{
		if (x[i] % 2 && y[i] % 2) k = x[i]*y[i]+0.41;
		else k = x[i]*y[i];
		cout << "\nScenario #" << i+1 << ":\n" << k << "\n";
	}
}