#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>
#include <math.h>
#include <time.h>

using namespace std;

#define DEBUG
#undef DEBUG
#define FILE
#undef FILE

#ifdef FILE
#define cin in
#define cout out
fstream in("input.txt", ios::in), out("output.txt", ios::out);
#endif FILE

//---------------------VAR---------------------

pair < long long, long long > Apair, Bpair, Cpair;

//---------------------VAR---------------------

//---------------------FUNC--------------------
double __Square_abc()
{
	double ans = 0;

	ans = ans + (double) (Apair.second + Bpair.second)*(Apair.first - Bpair.first) / 2;
	ans = ans + (double) (Cpair.second + Bpair.second)*(Cpair.first - Bpair.first) / 2;
	ans = ans + (double) (Apair.second + Cpair.second)*(Apair.first - Cpair.first) / 2;

	return abs(ans);
}

double __pAB(pair < long long, long long > a, pair < long long, long long > b)
{
	if (a.first == b.first) return (double) (abs(a.second - b.second) - 1);
	if (a.second == b.second) return (double) (abs(a.first - b.first) - 1);

	if (a.first > b.first) swap(a, b);

	long long ans = 0;

	for (int i = a.first + 1; i < b.first; i++) 
		if ((i - a.first)*(b.second - a.second) % (b.first - a.first) == 0) ans++;

	return (double) ans;
}
//---------------------FUNC--------------------

int main()
{
	//---------------------IN----------------------

	Apair = make_pair(0, 0);
	Bpair = make_pair(0, 0);
	Cpair = make_pair(0, 0);

	bool fl = true;

	while (fl)
	{
		cin >> Apair.first >> Apair.second >> Bpair.first >> Bpair.second >> Cpair.first >> Cpair.second;

		if (Apair.first == 0 && Apair.second == 0 && Bpair.first == 0 && Bpair.second == 0 && Cpair.first == 0 && Cpair.second == 0) fl = false;

		cout << (__Square_abc() + 1 - (3 + __pAB(Apair, Bpair) + __pAB(Cpair, Bpair) + __pAB(Cpair, Apair)) / 2) << endl;
	}

	//---------------------IN----------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN---------------------



	//--------------------MAIN---------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}