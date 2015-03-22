//0962 - Lamzin Oleh
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

ll vect[4][2];
double maX;

double len(ll a, ll b)
{
    return sqrt(pow(vect[a][0]- vect[b][0],2) + pow(vect[a][1]- vect[b][1],2));
}

int main()
{
    for (int i = 0; i < 4; i++) cin >> vect[i][0] >> vect[i][1];
    
    maX = len(0, 3);
    
    for (int i = 1; i<4; i++) maX = max(maX, len(i-1, i));
    
    cout.precision(2);
    cout << fixed <<  maX << endl;
}