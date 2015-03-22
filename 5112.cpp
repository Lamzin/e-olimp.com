#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

#define PI 3.14159265358979323846

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

long long a, b;

int main()
{
	cin >> a >> b;
	if (a + b == 1) cout << "2" << endl;
	else cout << "1" << endl;
}