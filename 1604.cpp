#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <math.h>
#include <time.h>

#define DEBUG
#undef DEBUG
#define PI 3.14159265358979323846
using namespace std;
fstream in("input.txt", ios::in), out("output.txt", ios::out);

long long tmp, d = -1;

int main()
{
	//---------------------IN---------------------

	cin >> tmp;

	//---------------------IN---------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN--------------------

	tmp = abs(tmp);

	if (tmp == 0) d = 0;

	while (tmp)
	{
		if (tmp % 10 % 2 == 0) d *= tmp % 10;
		tmp /= 10;
	}

	cout << ((d == -1) ? d : -d) << endl;

	//--------------------MAIN--------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}