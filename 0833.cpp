#include <iostream>
using namespace std;

pair <long long, long long> A, B, C, O;

int main()
{
	cin >> A.first >> A.second >> B.first >> B.second >> C.first >> C.second >> O.first >> O.second;
	long long X, Y, Z;
	X = (A.first - O.first) * (B.second - A.second) - (B.first - A.first) * (A.second - O.second);
	Y = (B.first - O.first) * (C.second - B.second) - (C.first - B.first) * (B.second - O.second);
	Z = (C.first - O.first) * (A.second - C.second) - (A.first - C.first) * (C.second - O.second);

	if ((X >= 0 && Y >= 0 && Z >= 0) || (X <= 0 && Y <= 0 && Z <= 0)) cout << "In" << endl;
	else cout << "Out" << endl;
}