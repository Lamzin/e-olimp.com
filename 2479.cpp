//2479 - Lamzin Oleh
#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

#define cin in
#define cout out
#define re return

int n;
string str;

string f()
{
   if (str == "") re "Yes";
   
   stack <bool> st;
   for (int i = 0; i < str.length(); i++)
   {
       switch(str[i])
       {
           case '(':
               st.push(true);
               break;
           case ')':
               if (st.empty()) re "No";
               else if (!st.top()) re "No";
               else st.pop();
               break;
           case '[':
               st.push(false);
               break;
           case ']':
               if (st.empty()) re "No";
               else if (st.top()) re "No";
               else st.pop();
               break;
       }
   }
   if (!st.empty()) re "No";
   
   re "Yes";
}

int main()
{
   cin >> n;
   getline(cin, str);
   
   for (int i = 0; i<n; i++)
   {
       getline(cin, str);
       
       cout << f() << endl;
   }
}