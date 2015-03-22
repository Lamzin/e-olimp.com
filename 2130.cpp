//2147 - Lamzin Oleh
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

pair<double, double> a,b,len;
double alpha, ab;

int main()
{
  cin >> a.first >> a.second >> b.first >> b.second;
  
  ab = a.first*b.first + a.second*b.second;
  len.first = sqrt(pow(a.first,2) + pow(a.second,2));
  len.second = sqrt(pow(b.first,2) + pow(b.second,2));
  
  alpha = ab / sqrt((pow(a.first,2) + pow(a.second,2))*(pow(b.first,2) + pow(b.second,2)));
  //if (alpha < 0) alpha*=-1;
  
  cout.precision(5);
  cout << fixed << acos(alpha) << endl;
}