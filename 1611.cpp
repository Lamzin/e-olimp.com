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


string str;
long long a, b;

int main()
{
	//---------------------IN---------------------

	cin >> str >> a >> b;
	a--; b--;
	if (a > b) swap(a, b);

	//---------------------IN---------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN--------------------

	string A = "", B = "", C = "";

	for (int i = 0; i < a; i++) A += str[i];
	for (int i = a; i <= b; i++) B += str[i];
	for (int i = b+1; i < str.length(); i++) C += str[i];

	for (int i = 0; i < B.length() / 2; i++) swap(B[i], B[B.length() - i - 1]);

	cout << A + B + C << endl;

	//--------------------MAIN--------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}