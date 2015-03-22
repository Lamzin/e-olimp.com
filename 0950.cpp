//0950 - Lamzin Oleh
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

#define ll long long
#define cin in
#define cout out

pair <ll, ll> a, b;

int main()
{
    cin >> a.first >> a.second >> b.first >> b.second;
    
    cout.precision(3);
    cout << fixed
        << (double)abs(a.first * a.second) << " "
        << (double)abs(a.first * (a.second - b.second)) << " "
        << (double)abs((a.first - b.first)*(a.second - b.second)) << " "
        << (double)abs(a.second * (a.first - b.first)) << endl;

}