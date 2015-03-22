#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long n, answer = 0;

int main()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	if (n / i == n % i) answer++;
	cout << answer << endl;
}