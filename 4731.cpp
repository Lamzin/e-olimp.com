#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector <long long> vect;
long long tmp, max_ct = 0, M = 0;

int main()
{
	do
	{
		cin >> tmp;
		if (tmp)
		{
			vect.push_back(tmp);
		}
	} while (tmp);

	for (int i = 0; i < vect.size(); i++)
	{
		if (vect[i] > M) M = vect[i];
	}

	for (int i = 0; i < vect.size(); i++)
	if (vect[i] == M) max_ct++;
	
	cout << max_ct << endl;
}