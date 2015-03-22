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

typedef char s8;
typedef short int s16;
typedef int s32;
typedef long long int s64;
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned int u32;
typedef unsigned long long int u64;
typedef float f32;
typedef double f64;
typedef u8 byte;

//---------------------VAR---------------------

int n, qSize, index;
pair <int, int> que[3000000];
vector <int> vect;

//---------------------VAR---------------------

//---------------------FUNC--------------------
//---------------------FUNC--------------------
int main()
{
	//---------------------IN----------------------

	cin >> n;

	//---------------------IN----------------------

#ifdef DEBUG
	double timeStart = clock();
#endif

	//--------------------MAIN---------------------

	que[0] = make_pair(n, 0);
	index = 0; qSize = 1;

	while (que[index].first != 1)
	{
		if (que[index].first % 2 == 0) que[qSize++] = make_pair(que[index].first / 2, index);
		if (que[index].first % 3 == 0) que[qSize++] = make_pair(que[index].first / 3, index);
		if (que[index].first % 3 < 2 || que[index].first % 2) que[qSize++] = make_pair(que[index].first - 1, index);
		index++;
	}

	while (index)
	{
		vect.push_back(que[index].first);
		index = que[index].second;
	}
	vect.push_back(n);

	sort(vect.begin(), vect.end());
	cout << vect.size() - 1 << endl << vect[0];
	for (int i = 1; i < vect.size(); i++) cout << " " << vect[i];
	cout << endl;

	//--------------------MAIN---------------------

#ifdef DEBUG
	cout.precision(3);
	cout << "\n=======\n\nTime = " << fixed << (clock() - timeStart) / CLOCKS_PER_SEC;
	cin >> timeStart;
#endif
}