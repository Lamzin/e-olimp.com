//2316 - Lamzin Oleh
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>
#include <vector>
#include <math.h>

using namespace std;

fstream in("input.txt", ios::in), out("output.txt", ios::out);

#define ll long long
//#define cin in
//#define cout out

struct g
{
    ll a;
    g *left, *right;
    
    g(ll _a)
    {
        a = _a;
        left  = right = NULL;
    }
    g()
    {
        left  = right = NULL;
    };
};

g head;
ll tmp;
bool space = false;

void check(g *hd)
{
    if ((*hd).left == NULL && (*hd).right == NULL)
    {
        if (space) cout << " ";
        cout << (*hd).a;
        space = true;
    }
    else
    {
        if ((*hd).left != NULL) check((*hd).left);
        if ((*hd).right != NULL) check((*hd).right);
    }
}

void push(g *hd, ll x)
{
    if (x < (*hd).a)
    {
        if ((*hd).left == NULL) (*hd).left = new g(x);
        else push((*hd).left, x);
    }
    else if (x > (*hd).a)
    {
        if ((*hd).right == NULL) (*hd).right = new g(x);
        else push((*hd).right, x);
    }    
}

int main()
{
    cin >> tmp;

    if (tmp) 
    {
        head.a = tmp;
    
        while (tmp)
        {
           cin >> tmp; 
           if (tmp) push(&head, tmp);
        }
        
        check(&head);
    }

    cout << endl;
}