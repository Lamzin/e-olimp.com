#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <math.h>
#include <time.h>

using namespace std;

#define DEBUG
#undef DEBUG
#define FILE
//#undef FILE

#ifdef FILE
#define cin in
#define cout out
fstream in("input.txt", ios::in), out("output.txt", ios::out);
#endif FILE

pair <double, double> a, b, c;

double getD()
{
	double AB, BC, CA, S, p;

	AB = hypot(a.first - b.first, a.second - b.second);
	BC = hypot(c.first - b.first, c.second - b.second);
	CA = hypot(a.first - c.first, a.second - c.second);

	p = (AB + BC + CA) / 2;
	 
	S = sqrt(p*(p-AB)*(p-BC)*(p-CA));

	return AB * BC * CA / S / (double)2;
}

int main()
{
#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN--------------------

	cout.precision(2);

	while (cin)
	{
		cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;
		if (cin)
		{
			cout << fixed << getD() * 3.141592653589793 << endl; 
		}
	}

	//--------------------MAIN--------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}