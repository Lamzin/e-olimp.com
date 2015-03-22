#include <iostream>
#include <vector>

#define SIZE 100

using namespace std;

int n, m, tmpa, tmpb;
bool mas[SIZE][SIZE] = {false};
vector <bool> array;
vector <pair<int, int>> vect;
bool answer = true;

void recursion(int tmp, int number)
{
   for (int i = 0; i<n; i++)
       if (mas[tmp][i] == true) 
       {
           mas[tmp][i] = false;
           array[i] = true;
           vect.push_back(make_pair(i, number));
       }
}

int main()
{
  cin >> n >> m;
  for (int i = 0; i<n; i++)
      array.push_back(false);

  for (int itmp = 0; itmp < m; itmp++)
  {
      cin >> tmpa >> tmpb;
      tmpa--;  tmpb--;
      mas[tmpa][tmpb] = mas[tmpb][tmpa] = true;
  }

  for (int i = 0, j = 0; i<n; i++)
  {
      vect.clear();
      if (array[i] == false) 
      {
           array[i] = true; j = 0;
           vect.push_back(make_pair(i, 0));
           while (j < vect.size())
           {
               recursion(vect[j].first, vect[j].second + 1);
               j++;
           }
           for (int a = 0; a < vect.size() - 1; a++)
               for (int b = a+1; b < vect.size(); b++)
                   if (vect[a].first == vect[b].second && vect[a].second % 2 != vect[b].second % 2)
                   {
                       answer = false;
                   }
           }    
           if (!answer) break;
  }
    
  if (answer) cout << "YES\n";
  else cout << "NO\n";
}