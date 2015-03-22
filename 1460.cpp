//1460 - Lamzin Oleh
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
pair <ll, ll> ab;

void swap_vect(ll a, ll b)
{
    for (int i = 0; i<=(b-a)/2; i++) swap(vect[a+i], vect[b-i]);
}

int main()
{
    cin >> n;
    vect.reserve(n);
    for (int i = 0; i<n; i++) vect[i] = i+1;
    
    for (int i = 0; i<2; i++)
    {
        cin >> ab.first >> ab.second;
        swap_vect(ab.first-1, ab.second-1);
    }
    
    cout << vect[0];
    for (int i = 1; i<n; i++) cout << " " << vect[i];
    cout << endl;
}