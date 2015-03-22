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
#undef FILE

#ifdef FILE
#define cin in
#define cout out
fstream in("input.txt", ios::in), out("output.txt", ios::out);
#endif FILE

long long a, b;

int main()
{
	//---------------------IN---------------------

	while (cin)
	{
		cin >> a >> b;
		if (cin)
		{
			cout << 2 * a * b << endl;
		}
	}
	//---------------------IN---------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN--------------------






	//--------------------MAIN--------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}