//0941 - Lamzin Oleh
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

string s;
ll a = 0, b = 1;

int main()
{
   cin >> s;
   if (s[0] == '-') s.erase(0,1);
   while (s.length() < 3) s+='0';
   
   for (int i = 0; i<3; i++)
   {
       a += s[i] - 48;
       b *= s[i] - 48;
   }
   
   cout << b-a << endl;
}