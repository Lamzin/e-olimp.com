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
boudle timeStart = clock();
#endif

int n, tmp, ans = 1;
vector <int> vect;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		vect.push_back(tmp);
	}

	sort(vect.begin(), vect.end());

	for (int i = 1; i < n; i++)
	if (vect[i] != vect[i - 1]) ans++;

	if (n == 0) cout << 0 << endl;
	else cout << ans << endl;

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}