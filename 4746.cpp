#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

vector <int> vect;
int n, tmp, ans = 0;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		vect.push_back(tmp);
	}

	sort(vect.begin(), vect.end());

	for (int i = 0; i < n/2; i++)
		swap(vect[i], vect[n-1-i]);

	for (int i = 0; i < n; i++)
	if (vect[i] - i>0) ans += vect[i] - i;
	else break;

	cout << ans << endl;
}