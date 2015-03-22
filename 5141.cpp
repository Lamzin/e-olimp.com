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

int n, k, vect[300000], value_min = 1 << 30, index, tmp;

int main()
{
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> tmp;
		vect[i] = tmp;
		if (tmp <= value_min)
		{
			index = i;
			value_min = tmp;
		}
	}
	cout << value_min << endl;
	
	for (int i = k; i < n; i++)
	{
		cin >> tmp;
		vect[i] = tmp;

		if (index > i - k && value_min >= tmp)
		{
			index = i;
			value_min = tmp;
		}
		else if (index <= i - k)
		{
			value_min = 1 << 30;
			for (int j = i-k+1; j <= i; j++)
			if (vect[j] <= value_min)
			{
				index = j;
				value_min = vect[j];
			}
		}
		cout << value_min << endl;
	}


#ifdef DEBUG
	cout << "\n=======\n\nTime = " << time(NULL) - timeStart;
	cin >> timeStart;
#endif
}