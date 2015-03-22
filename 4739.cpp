#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

bool erat[100002];
long long a, b;
bool first = false;

int main()
{
	cin >> a >> b;
	if (a > b) swap(a, b);
	memset(erat, true, b+2);
	erat[0] = erat[1] = false;

	for (int i = 2; i <= b; i++)
	{
		if (erat[i])
		for (int j = i * 2; j <= b; j += i) erat[j] = false;
	}

	for (int i = a; i <= b; i++)
	{
		if (erat[i])
		{
			if (first) cout << " ";
			cout << i;
			first = true;
		}
	}
	/*if (first) */cout << endl;
}