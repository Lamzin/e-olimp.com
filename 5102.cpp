#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <time.h>

#define DEBUG
#undef DEBUG
#define PI 3.14159265358979323846
using namespace std;
fstream in("input.txt", ios::in), out("output.txt", ios::out);
#ifdef DEBUG
long long timeStart = time(NULL);
#endif

int n, x, y, ans, sum, index;

int gcd(int a, int b)
{
	if (b == 0) return a;
	else return gcd(b % a, a);
}

int main()
{
	cin >> n >> x >> y;
	ans = 1;
	sum = 0;
	ans = min(x,y);

	int NCK, kol;
	NCK = x * y / gcd(x, y);
	kol = NCK / x + NCK / y;
	ans += (n-1) / kol 


	while (sum < n)
	{
		if (ans % x == 0) sum++;
		if (ans % y == 0) sum++;
		if (sum < n) ans++;
	}
	cout << ans << endl;

#ifdef DEBUG
	cout << "\n=======\n\nTime = " << time(NULL) - timeStart;
	cin >> timeStart;
#endif
}