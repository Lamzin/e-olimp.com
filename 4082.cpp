#include <fstream>
#include <algorithm>
#include <iostream> 
#include <string>

using namespace std;

fstream in("input.txt", ios:: in), out("output.txt", ios:: out);

#define cin in
#define cout out
#define SIZE 100000
#define INF 1000000000
#define ll long long

int n, k, a, b;
char mas[SIZE];
char ch;

struct segment_tree
{
    int pos_left, pos_right;
    
    char product;
    
    segment_tree *left, *right;
};

segment_tree* build(int L, int R)
{
    segment_tree *Tree = new segment_tree;

    if (L == R)
    {
        Tree->product = mas[L];
        
        Tree->pos_left = Tree->pos_right = L;
        Tree->left = Tree->right = NULL;
        return Tree;
    }
    
    int M = (L + R) / 2;
    
    Tree->left = build(L, M);
    Tree->right = build(M+1, R);
    Tree->pos_left = L;
    Tree->pos_right = R;

    Tree->product = Tree->left->product * Tree->right->product;
    
    return Tree;
}

char product(segment_tree *Tree, int L, int R)
{
    if (L < Tree->pos_left) L = Tree->pos_left;
    if (R > Tree->pos_right) R = Tree->pos_right;
    if (L > R) return 1;
    
    if (Tree->pos_left == L && Tree->pos_right == R) return Tree->product;
    
    return product(Tree->left, L, R) * product(Tree->right, L, R);
}

void update(segment_tree *Tree, int position, char value)
{
    if (Tree->pos_left == Tree->pos_right)
    {
        Tree->product = value;
        return;
    }
    
    if (position < Tree->right->pos_left) update(Tree->left, position, value);
    else update(Tree->right, position, value);

    Tree->product = Tree->left->product * Tree->right->product;
}

int main()
{
    while(cin)
    {
        cin >> n >> k;
        if (cin)
        {
            int tmp_int;
            
            for (int i = 0; i<n; i++) 
            {
                cin >> tmp_int;
                if (tmp_int == 0) mas[i] = 0;
                else if (tmp_int > 0) mas[i] = 1;
                else mas[i] = -1;
            }

            segment_tree *Tree_main = new segment_tree; 
            Tree_main = build(0, n-1);

            for (int i = 0; i<k; i++) 
            {
                cin >> ch >> a >> b;

                if (ch == 'P')
                {
                    char tmp = product(Tree_main, a-1, b-1);
                    //cerr << "tmp = " << (int)tmp << endl;

                    if (tmp == 1) cout << "+";
                    else if (tmp == -1) cout << "-";
                    else cout << "0";
                }
                else 
                {
                    char tmp;
                    if (b == 0) tmp = 0;
                    else if (b > 0) tmp = 1;
                    else tmp = -1;
                    
                    update(Tree_main, a-1, tmp);
                }

            }
            
            cout << endl;
        }
    }
}