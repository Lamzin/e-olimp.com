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

long long n, tmp = 1, k = 0;

int main()
{
	cin >> n;

	while (tmp <= n) tmp *= 2, k++;

	if (tmp == 2*n) cout << "I="<< k-1 << endl;
	else cout << k - 1 << "<I<" << k << endl;


#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}