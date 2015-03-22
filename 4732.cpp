#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long n, answer = 1;
pair <long long, long long> fibo;

int main()
{
	cin >> n;
	fibo.first = fibo.second = 1;

	while (fibo.second != n)
	{
		answer++;
		swap(fibo.first, fibo.second);
		fibo.second += fibo.first;
	}

	cout << answer << endl;
}