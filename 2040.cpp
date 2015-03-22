//2040 - Lamzin Oleh
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

#define SIZE 1001

string a,b,res;
int mas[SIZE][SIZE];
pair <int, int>  ij;

int main()
{
   do
   {
       getline(cin, a);
       getline(cin, b);
       if (cin)
       {
           sort(&a[0], &a[a.length()]);
           sort(&b[0], &b[b.length()]);

           for (int i = 0; i<a.length()+1; i++)
               for (int j = 0; j<b.length()+1; j++)
               {
                   if (i*j == 0) mas[i][j] = 0;
                   else if (a[i-1] == b[j-1]) mas[i][j] = mas[i-1][j-1] + 1;
                   else mas[i][j] = max(mas[i-1][j], mas[i][j-1]);
               }

           ij.first = a.length();
           ij.second = b.length();

           res = "";
           while (ij.first > 0 && ij.second > 0)
           {
               if (mas[ij.first][ij.second] > max(mas[ij.first-1][ij.second], mas[ij.first][ij.second-1]))
               {
                   res+=b[ij.second-1];
                   ij.first--;
                   ij.second--;
               }
               else if (mas[ij.first][ij.second-1] == mas[ij.first][ij.second]) ij.second--;
               else if (mas[ij.first-1][ij.second] == mas[ij.first][ij.second]) ij.first--;
           }
           
           if (res != "")
           {
               for (int i = res.length()-1; i>=0; i--) cout << res[i];
           }    

           cout << endl;
       }
   }
   while (cin);
}