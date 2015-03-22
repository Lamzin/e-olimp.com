#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

long long n, tmp;
vector <long long> vect;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		vect.push_back(tmp);
	}

	sort(vect.begin(), vect.end());

	for (int i = 0; i < n; i++)
	{
		cout << vect[i];
		if (i != n - 1) cout << " ";
	}
	cout << endl;
}