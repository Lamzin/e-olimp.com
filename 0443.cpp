#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector <pair<long long, string>> vect;
vector <string> vectstr;
string strtmp;
long long n, k, tmp;


int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> strtmp >> tmp;
		vect.push_back(make_pair(tmp, strtmp));
	}
	sort(vect.begin(), vect.end());

	for (int i = 0; i < k; i++)
	{
		vectstr.push_back(vect[i].second);
	}
	sort(vectstr.begin(), vectstr.end());

	for (int i = 0; i < k; i++)
		cout << vectstr[i] << endl;
}