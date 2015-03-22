//2316 - Lamzin Oleh
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>
#include <vector>
#include <math.h>
#include <deque>
#include <map>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

#define ll unsigned int
//#define cin in
//#define cout out

ll n, a, b;
string str;
map <ll, deque <ll> > mp;

int main()
{
    cin >> n;
    for (int i = 0; i<n; i++)
    {
        cin >> str;
        if (str == "pushfront")
        {
            cin >> a >> b;
            mp[a].push_front(b);
        }
        else if (str == "pushback")
        {
            cin >> a >> b;
            mp[a].push_back(b);
        }
        else if (str == "popfront")
        {
            cin >> a;
            cout << mp[a].front() << endl;
            mp[a].pop_front();
        }
        else if (str == "popback")
        {
            cin >> a;
            cout << mp[a].back() << endl;
            mp[a].pop_back();
        }
    }
}