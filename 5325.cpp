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

int n;

int main()
{
	cin >> n;

	cout << 1;
	for (int i = 2; i <= n; i++) cout << " " << i;
	cout << endl;


#ifdef DEBUG
	cout << "\n=======\n\nTime = " << time(NULL) - timeStart;
	cin >> timeStart;
#endif
}