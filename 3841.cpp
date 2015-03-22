#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

#define SIZE 1000000

fstream in("input.txt", ios::in), out("output.txt", ios::out);

int vect[SIZE], size;
string str;

bool function()
{
    size++;
    sort(vect, vect + size);
    
    while(size > 1)
    {
        for(int i = size-2, k = vect[size-1]; k; i--, k--)
        {
            if (i == -1) return false;
            vect[i]--;
        }
        size--;
        
        sort(vect, vect + size);
        while(vect[0] == 0 && size > 1)
        {
            for (int i = 1; i<size; i++) vect[i-1] = vect[i];
            size--;
        }
        if (size == 1  && vect[0]) return false; 
    }
    
    return true;
}

int main()
{
    while(in)
    { 
        size = 0;
        for (int i = 0; i<SIZE; vect[i++] = 0);

        getline(in, str);
        
        if (in)
        {
            for (int i = 0; i<str.length(); i++)
            {
                if (str[i] != ' ') vect[size] = vect[size]*10 + str[i] - 48;  
                else size++;        
            }

            if (function()) out << "ok\n\n";
            else out << "fail\n\n";
        }
    }
}