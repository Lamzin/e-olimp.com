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

string A = "1", B;
int n = 1;

int main()
{
	cin >> B;

	for (int i = 0; i < B.length()/2; i++) swap(B[i], B[B.length() - i - 1]);;

	if (B == "1") cout << 1 << endl;
	else
	{
		while (A != B)
		{
			n++;
			
			int ost = 0;

			for (int i = 0; i < A.length(); i++)
			{
				ost += (A[i] - 48) * n;
				A[i] = ost % 10 + 48;
				ost /= 10;
			}
			while (ost)
			{
				A += ost % 10 + 48;
				ost /= 10;
			}
		}

		cout << n << endl;
	}


#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}