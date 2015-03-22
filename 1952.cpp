//1952 - Lamzin Oleh
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

ll n;
vector <ll> vect;
pair <ll, ll> minmax;

int main()
{
    cin >> n;
    
    vect.reserve(n);

    cin >> vect[0];
    minmax.first = minmax.second = vect[0];
    
    for (int i = 1; i<n; i++)
    {
        cin >> vect[i];
        minmax.first = min(minmax.first, vect[i]);
        minmax.second = max(minmax.second, vect[i]);
    }
    
    for (int i = 0; i<n; i++)
    {
        if (vect[i] == minmax.second) vect[i] = minmax.first;
        cout << vect[i] << ((i<n-1)?" ":"\n");
    }
}