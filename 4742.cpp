#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

long long n, ans = 0, sq;

int main()
{
	cin >> n;
	sq = sqrt(n);

	for (int i = 2; i <= sq; i++)
	if (!(n % i)) ans++;
	
	ans *= 2;
	
	if (sq*sq == n) ans--;

	cout << ans << endl;
}