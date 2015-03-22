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
vector <string> vect;
string tmp;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		vect.push_back("");
		cin >> vect[i];
	}

	sort(vect.begin(), vect.end());

	for (int i = 0; i < n; i++)
	{
		cout << vect[i] << endl;
	}

#ifdef DEBUG
	cout << "\n=======\n\nTime = " << time(NULL) - timeStart;
	cin >> timeStart;
#endif
}