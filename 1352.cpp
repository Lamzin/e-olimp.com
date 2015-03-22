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

#define SIZE (1024 * 1024 * 2)

bitset <SIZE> bit;
long long n = 0, k, sum = 0, ind = 2;

int main()
{
	//---------------------IN---------------------

	cin >> k;

	//---------------------IN---------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN--------------------

	bit[0] = bit[1] = false;

	sum = 2; ind = 3; n = 1;

	for (int i = 4; i < SIZE; i+=2) bit[i] = true;

	while (sum % k)
	{
		if (!bit[ind])
		{
			n++;
			sum += ind;

			for (int i = ind * 2; i < SIZE; i+=ind) bit[i] = true;
		}
		ind++;
		if (ind > SIZE) return 0;
	}

	cout << n << endl;

	//--------------------MAIN--------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}