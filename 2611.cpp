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

string str;
int a, b, l,r;
bool dot = false;

int main()
{
	cin >> str >> a >> b;

	l = 0; r = str.length()-1;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == a + 48) str[i] = b + 48;
		if (str[i] == ',') dot = true;
	}
	while (str[l] == '0') l++;
	if (dot) while (str[r] == '0') r--;
 
	if (dot && str[1] == ',') l = 0;

	for (int i = l; i <= r; i++) cout << str[i];
	if (l > r) cout << 0;

	cout << endl;

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}