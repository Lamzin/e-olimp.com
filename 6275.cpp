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

int a;

int main()
{
	cin >> a;
	if (a > 0)
	{
		cout << a / 100 << a / 100 << a / 10 % 10 << a / 10 % 10 << a % 10 << a % 10 << endl;
	}
	else
	{
		a = abs(a);
		cout << "-" << a / 100 << a / 100 << a / 10 % 10 << a / 10 % 10 << a % 10 << a % 10 << endl;
	}

#ifdef DEBUG
	cout << "\n=======\n\nTime = " << time(NULL) - timeStart;
	cin >> timeStart;
#endif
}