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

long long a, b, ans;

int main()
{
	cin >> a >> b;
	switch (a)
	{
	case 1: ans = 31; break;
	case 2: ans = (!(b % 4) && b % 100 || !(b % 400))?29:28; break;
	case 3: ans = 31; break;
	case 4: ans = 30; break;
	case 5: ans = 31; break;
	case 6: ans = 30; break;
	case 7: ans = 31; break;
	case 8: ans = 31; break;
	case 9: ans = 30; break;
	case 10: ans = 31; break;
	case 11: ans = 30; break;
	case 12: ans = 31; break;
	}
	cout << ans << endl;

#ifdef DEBUG
	cout << "\n=======\n\nTime = " << time(NULL) - timeStart;
	cin >> timeStart;
#endif
}