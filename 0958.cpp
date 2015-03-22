//0958 - Lamzin Oleh
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

double b, a, S, A, B, A2, cos_c;

int main()
{
    cin >> b >> a;
    a *= M_PI / 180;

    A = 2 * b*cos(a) / sqrt(2);
    
    S = A*A;
    
    A2 = A / 2;
    
    B = b * sin(a);
    
    cos_c = A2 / sqrt(A2*A2 + B*B);
    
    cout.precision(3);
    cout << fixed << S * (1 + 1 / cos_c) << endl;
}