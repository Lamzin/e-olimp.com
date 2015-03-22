#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <time.h>

#define DEBUG
#undef DEBUG
#define PI 3.14159265358979323846
using namespace std;
fstream in("input.txt", ios::in), out("output.txt", ios::out);
#ifdef DEBUG
boudle timeStart = clock();
#endif

int n, k3 = 0, k4 = 0, k5 = 0, tmp;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp == 5) k5++;
		else if (tmp == 4) k4++;
		else k3++;
	}

	if (k3 < 2 && 4 * (k3 + k4) <= n)
		cout << "Degree with honors" << endl;
	else cout << "Ordinary degree" << endl;


#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}