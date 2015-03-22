//1871 - Lamzin Oleh
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

#define cin in
#define cout out
#define re return

int n, tmp;
stack <int> st;

int main()
{
   cin >> n;
   
   st.push(0);
   
   for (int i = 0; i<n; i++)
   {
       cin >> tmp;
       
       if (tmp) st.push(max(st.top(), tmp));
       else 
       {
           st.pop();
           cout << st.top() << endl;
       }
   }
}