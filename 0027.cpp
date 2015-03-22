#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector <bool> vect;
bool btmp;
int n, answer = 0, tmp, maxbinpow = 1;

int main()
{
	cin >> n;
	answer = n;

	while (maxbinpow * 2 < answer) maxbinpow *= 2;
	
	tmp = (n - maxbinpow) * 2 + 1;
	while (tmp != n)
	{
		answer = max(tmp, answer);
		if (tmp > maxbinpow)
		{
			tmp = (tmp - maxbinpow) * 2 + 1;
		}
		else
		{
			tmp *= 2;
		}
	}
	cout << answer << endl;
}