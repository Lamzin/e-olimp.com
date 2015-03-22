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

string sa, sb;
long long a = 0, b = 0;

int main()
{
	//---------------------IN---------------------

	while (cin)
	{
		cin >> sa >> sb;
		if (cin)
		{
			a = b = 0;
			for (int i = sa[0] == '-'; i < sa.length(); i++) if (sa[i] != ',') a = a * 10 + sa[i] - 48;
			if (sa[0] == '-') a *= -1;
			for (int i = sb[0] == '-'; i < sb.length(); i++) if (sb[i] != ',') b = b * 10 + sb[i] - 48;
			if (sb[0] == '-') b *= -1;

			cout << a + b << endl;
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