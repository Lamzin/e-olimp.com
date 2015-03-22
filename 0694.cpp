//0694 - Lamzin Oleh
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

ll a,b,c,n,x0,ans = 0;
pair <ll, ll> index = make_pair(0,-1), miN = make_pair(-1,1000000);

vector <ll> vect;

int main()
{
   cin >> n >> a >> b >> c >> x0;
   
   vect.reserve(n);
   
   for (ll i = 0; i < n; i++)
   {
       x0 = (a * x0 * x0 + b * x0 + c) / 100 % 1000000;
       
       if (x0 % 5 < 2)
       {
           if (index.first <= index.second) 
           {
               index.first++;
           }
           
           if (index.first <= index.second) 
           {
                if (miN.first < index.first)
                {
                    miN.second = vect[index.first];
                    miN.first = index.first;
                    for (ll j = index.first+1; j<=index.second; j++)
                        if (vect[j] <= miN.second)
                        {
                            miN.first = j;
                            miN.second = vect[j];
                        }
                }
                ans += miN.second;
           }
       }
       else
       {
           if (index.first > index.second) 
           {
               miN.first = index.second + 1;
               miN.second = x0;
           }
           
           index.second++;
           vect[index.second] = x0;

           if (vect[index.second] <= miN.second)
           {
               miN.first = index.second;
               miN.second = vect[index.second];
           }
           
           ans += miN.second;
       }
       
   }
   
   cout << ans << endl;
    
}