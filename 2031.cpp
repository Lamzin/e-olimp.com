//2031 - Lamzin Oleh
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

#define ll long long
#define DEBUG
#ifdef DEBUG
    #define cin in
    #define cout out
#endif

vector <unsigned ll> vect;
ll n;

int main()
{
    vect.push_back(1);
    vect.push_back(1);

    cin >> n;
    
    for (int i = 2; i<n; i++) vect.push_back(vect[i-1] + vect[i-2]);
    
    for (int i = 0; i<n; i++) cout << vect[i] << endl;
}