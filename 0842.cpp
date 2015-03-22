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

long long n;
vector <long long> vect;

int main()
{
	//---------------------IN---------------------
	cin >> n;
	//---------------------IN---------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN--------------------

	if (n == 1)
	{
		cout << 1 << endl;
	}
	else
	{
		while (n % 2 == 0)
		{
			vect.push_back(2);
			n /= 2;
		}

		for (int i = 3; i*i <= n; i+=2)
		{
			if (n % i == 0)
			while (n % i == 0)
			{
				vect.push_back(i);
				n /= i;
			}
		}

		if (n != 1) vect.push_back(n);

		cout << vect[0];
		for (int i = 1; i < vect.size(); i++) cout << "*" << vect[i];
		cout << endl;
	}
	//--------------------MAIN--------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}