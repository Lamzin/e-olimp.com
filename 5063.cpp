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

int n, m, tmp, mas[1000000];

int main()
{
	cin >> n >> m;
	//memset(mas, false, 100000);
	for (int i = 0; i < n; i++)
	{
		cin >> mas[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> tmp;
		if (find(mas, mas + n, tmp) != mas + n) cout << "Yes, master!" << endl;
		else cout << "Silence" << endl;
	}	

#ifdef DEBUG
	cout << "\n=======\n\nTime = " << time(NULL) - timeStart;
	cin >> timeStart;
#endif
}