#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MIN(a, b) ((a<b) ? a : b)

long int n;
vector <long> vect;
vector <long> length;

int main()
{
	cin >> n;

	for (long itmp = 0, tmp; itmp < n; itmp++)
	{
		cin >> tmp;
		vect.push_back(tmp);
	}

	sort(vect.begin(), vect.end());

	for (long itmp = 0; itmp < n - 1; itmp++)
	{
		length.push_back(vect[itmp+1] - vect[itmp]);
	}

	if (n > 2) length[1] = length[1] + length[0];

	for (long itmp = 2; itmp < n - 1; itmp++)
	{
		length[itmp] += MIN(length[itmp-1], length[itmp-2]);
	}

	cout << length[n-2] << endl;

	return 0;
}