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
long long timeStart = time(NULL);
#endif

int n, value = 1 << 30, tmp;
string best, read;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		tmp = 0;

		cin >> read;
		for (int j = 0; j < read.length(); j++) tmp += read[j] - 48;
		if (tmp <= value)
		{
			value = tmp;
			best = read;
		}
	}
	cout << best << endl;

#ifdef DEBUG
	cout << "\n=======\n\nTime = " << time(NULL) - timeStart;
	cin >> timeStart;
#endif
}