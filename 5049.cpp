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

int main()
{
	getline(cin, str);

	if (str.length() > 0)
	{

		cout << str[0];

		for (int i = 1; i < str.length(); i++)
		if (str[i] != ' ') cout << str[i];
		else if (str[i] == ' ' && str[i - 1] != ' ') cout << str[i];
	}

	cout << endl;

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}