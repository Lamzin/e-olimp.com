//6122 - Lamzin Oleh
#include <iostream>
#include <stack>
#include <string>

#include <fstream>

using namespace std;

string str, tmp;
stack <string> st;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

#define cin in
#define cout out

int main()
{
    do
    {
        //getline(cin, str);
        cin >> str;
        if (str == "pop")
        {
            cout << st.top() << endl;
            st.pop();
        }
        else if (str == "back")
        {
            cout << st.top() << endl;
        }
        else if (str == "size")
        {
            cout << st.size() << endl;
        }
        else if (str == "clear")
        {
            cout << "ok" << endl;
            while (!st.empty()) st.pop();
        }
        else if (str == "exit")
        {
            cout << "bye" << endl;
        }
        else
        {
            cin >> str;
            cout << "ok" << endl;
            st.push(str);
        }
    }
    while (str != "exit");
}