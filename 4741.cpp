#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

long long n, tmp, ans = 0;
vector <long long> vect;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		vect.push_back(tmp);
	}

	for (int i = 0; i < vect.size()-1; i++)
	{
		for (int j = 0; j < vect.size()-i; j++)
		{
			if (vect[j] > vect[j+1])
			{
				ans++;
				swap(vect[i], vect[j]);
			}
		}
	}
	
	cout << ans << endl;
}