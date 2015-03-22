//1776 - Lamzin Oleh
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

#define cin in
#define cout out
#define re return

int n, tmp;
vector < pair <int, int> > vect;
vector <int> mas;
pair <int, int> pa;
bool ans;

int main()
{
    do
    {
        cin >> n;
        //cout << "n = " << n << ";" << endl;
        if (n)
        {
            do
            {
                cin >> tmp;

                //cout << "tmp = " << tmp << ";" << endl;
                if (tmp)
                {
                    ans = true;
                    vect.clear();
                    mas.clear();
                    mas.push_back(tmp);
                    for(int i = 1; i<n; i++)
                    {
                        cin >> tmp;
                       // cout << "tmp = " << tmp << ";" << endl;
                        mas.push_back(tmp);
                    }

                    pa.first = pa.second = mas[0];

                    for (int i = 1; i<n; i++)
                    {
                        if (pa.second == mas[i] + 1) pa.second = mas[i];
                        else
                        {
                           vect.push_back(pa); 
                           pa.first = pa.second = mas[i]; 
                        }
                    }

                    vect.push_back(pa); 

                    for (int i = 1; i<vect.size(); i++)
                    {
                        if (vect[i-1].first != vect[i].second - 1)
                        {
                            ans = false;
                            break;
                        }
                    }

                    if (ans) cout << "Yes" << endl;
                    else cout << "No" << endl;
                }
                else cout << endl;
            }
            while (tmp);
        }
    }
    while (n);
}