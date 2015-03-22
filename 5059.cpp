#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

#define PI 3.14159265358979323846

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

pair <long long, long long> ans;
long long n, tmp;

int main()
{
	cin >> n;
	cin >> ans.first >> ans.second;
	if (ans.first > ans.second) swap(ans.first, ans.second);
	for (long long i = 2; i < n; i++)
	{
		cin >> tmp;
		if (tmp < ans.first)
		{
			ans.second = ans.first;
			ans.first = tmp;
		}
		else if (tmp < ans.second)
		{
			ans.second = tmp;
		}
	}

	cout << ans.first << " " << ans.second << endl;
}