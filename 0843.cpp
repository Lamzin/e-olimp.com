#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <math.h>
#include <time.h>

#define DEBUG
#undef DEBUG
#define PI 3.14159265358979323846
using namespace std;
fstream in("input.txt", ios::in), out("output.txt", ios::out);
#ifdef DEBUG
double timeStart = clock();
#endif

vector <char> vect;
string str;
int x, y;

int main()
{
	cin >> str;

	for (int i = 0; i < str.length(); i++) vect.push_back(str[i]);

	sort(vect.begin(), vect.end());

	for (;;)
	{
		for (int i = 0; i < vect.size(); i++) cout << vect[i]; cout << endl;

		x = vect.size() - 2;
		while (x >= 0 && vect[x] >= vect[x + 1]) x--;
		if (x < 0) break;

		y = x + 1;
		while (y < vect.size() - 1 && vect[y + 1] > vect[x]) y++;

		swap(vect[x], vect[y]);

		sort(vect.begin() + x + 1, vect.end());
	}

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}