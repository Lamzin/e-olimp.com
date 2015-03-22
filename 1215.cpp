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

string str1, str2;
int n, m, ans;

int main()
{
	//---------------------IN---------------------

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		ans = 0;
		for (int j = 0; j < m; j++)
		{
			cin >> str1 >> str2;

			if (str1 == "P" && str2 == "R") ans++;
			if (str1 == "P" && str2 == "S") ans--;

			if (str1 == "R" && str2 == "P") ans--;
			if (str1 == "R" && str2 == "S") ans++;

			if (str1 == "S" && str2 == "P") ans++;
			if (str1 == "S" && str2 == "R") ans--;
		}

		if (ans == 0) cout << "TIE" << endl;
		else if (ans > 0) cout << "Player 1" << endl;
		else cout << "Player 2" << endl;
	}

	//---------------------IN---------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN--------------------





	
	//--------------------MAIN--------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}