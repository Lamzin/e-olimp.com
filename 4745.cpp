#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

int n, tmp, ans = 0;

vector <int> vect;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		vect.push_back(tmp);
	}
	
	for (int i = 1; i < n - 1; i++)
	{
		if (vect[i] > vect[i - 1] && vect[i] > vect[i + 1]) ans++;
	}

	cout << ans << endl;
}