#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

int n;

int main()
{
	cin >> n;
	//n = ((n - n/10 - n%10) / 9 + 1)*10 + (n%10) - 10;
	cout << ((n - n / 10 - n % 10) / 9 + 1) * 10 + (n % 10) - 10 << endl;
}