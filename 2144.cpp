//2144 - Lamzin Oleh
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>
#include <vector>
#include <math.h>
#include <stdlib.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

#define ll long long
#define cin in
#define cout out

double len, A, B, C;
pair <double, double> xy;

int main()
{
    cin >> xy.first >> xy.second >> A >> B >> C;
    
    len = (A*xy.first + B*xy.second + C) / sqrt(A*A + B*B);
    if (len < 0) len*= -1;
    
    cout.precision(6);
    cout << fixed << len << endl;
}