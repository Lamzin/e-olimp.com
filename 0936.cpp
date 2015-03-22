//0936 - Lamzin Oleh
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

double a1,a2,b1,b2,c1,c2,x,y;

int main()
{
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    y = (a1*c2 - a2*c1)/(a1*b2 - a2*b1);
    x = (c1- b1*y) / a1;
    
    cout.precision(3);
    
    cout << fixed << x << endl << y << endl;
}