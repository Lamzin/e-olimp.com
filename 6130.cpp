//6130 - Lamzin Oleh
#include <iostream>
#include <deque>
#include <string>

#include <fstream>

using namespace std;

string str;
deque <string> deq;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

#define cin in
#define cout out

int main()
{
    do
    {
        cin >> str;
        
        if (str == "push_front")
        {
            cin >> str;
            cout << "ok" << endl;
            deq.push_front(str);
        }
        else if (str == "push_back")
        {
            cin >> str;
            cout << "ok" << endl;
            deq.push_back(str);
        }
        else if (!deq.size() & (str == "pop_front" | str == "pop_back" | str == "front" | str == "back"))
        {
            cout << "error" << endl;
        }
        else if (str == "pop_front")
        {
            cout << deq.front() << endl;
            deq.pop_front();
        }
        else if (str == "pop_back")
        {
            cout << deq.back() << endl;
            deq.pop_back();
        }
        else if (str == "front")
        {
            cout << deq.front() << endl;
        }
        else if (str == "back")
        {
            cout << deq.back() << endl;
        }
        else if (str == "size")
        {
            cout << deq.size() << endl;
        }
        else if (str == "clear")
        {
            cout << "ok" << endl;
            //while (!st.empty()) st.pop();
            deq.clear();
        }
        else if (str == "exit")
        {
            cout << "bye" << endl;
        }
    }
    while (str != "exit");
}