//0956 - Lamzin Oleh
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

double v,h;

int main()
{
    cin >> v >> h;
    
    cout.precision(1);
    cout << fixed << (3*v/h) / sqrt(3*v / (3*v + 4*h*h*h)) << endl;
}