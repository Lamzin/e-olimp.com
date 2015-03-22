#include <fstream>
#include <algorithm>
#include <iostream> 
#include <string>

using namespace std;

fstream in("input.txt", ios:: in), out("output.txt", ios:: out);

#define cin in
#define cout out
#define SIZE 1000000
#define INF 1000000000
#define ll long long

int n, k, a, b, weight;
int mas[SIZE], min_tmp[4];
char ch;

struct min12
{
    int first, second;
    min12(int f, int s)
    {
        first = f;
        second = s;
    }
    min12()
    {
        first = second = INF;
    }
};

struct segment_tree
{
    int pos_left, pos_right;
    
    min12 min;
    
    segment_tree *left, *right;
};

segment_tree* build(int L, int R)
{
    segment_tree *Tree = new segment_tree;

    if (L == R)
    {
        Tree->min.first = mas[L];
        Tree->min.second = INF;
                
        Tree->pos_left = Tree->pos_right = L;
        Tree->left = Tree->right = NULL;
        return Tree;
    }
    
    int M = (L + R) / 2;
    
    Tree->left = build(L, M);
    Tree->right = build(M+1, R);
    Tree->pos_left = L;
    Tree->pos_right = R;

    min_tmp[0] = Tree->left->min.first;
    min_tmp[1] = Tree->left->min.second;
    min_tmp[2] = Tree->right->min.first;
    min_tmp[3] = Tree->right->min.second;

    sort(min_tmp, min_tmp + 4);
    Tree->min.first = min_tmp[0];
    Tree->min.second = min_tmp[1];

    return Tree;
}

min12 sum_min_two(segment_tree *Tree, int L, int R)
{
    min12 min12_tmp;
    min12_tmp.first = min12_tmp.second = INF;
    
    if (L < Tree->pos_left) L = Tree->pos_left;
    if (R > Tree->pos_right) R = Tree->pos_right;
    if (L > R) return min12_tmp;
    
    if (Tree->pos_left == L && Tree->pos_right == R) return Tree->min;
    
    min12 left_min = sum_min_two(Tree->left, L, R), 
          right_min = sum_min_two(Tree->right, L, R);
    
    min_tmp[0] = left_min.first;
    min_tmp[1] = left_min.second;
    min_tmp[2] = right_min.first;
    min_tmp[3] = right_min.second;

    sort(min_tmp, min_tmp + 4);

    min12_tmp.first = min_tmp[0];
    min12_tmp.second = min_tmp[1];
    
    return min12_tmp;
}

void update(segment_tree *Tree, int position, int value)
{
    if (Tree->pos_left == Tree->pos_right)
    {
        Tree->min.first = value;
        Tree->min.second = INF;
        return;
    }
    
    if (position < Tree->right->pos_left) update(Tree->left, position, value);
    else update(Tree->right, position, value);
    
    min_tmp[0] = Tree->left->min.first;
    min_tmp[1] = Tree->left->min.second;
    min_tmp[2] = Tree->right->min.first;
    min_tmp[3] = Tree->right->min.second;

    sort(min_tmp, min_tmp + 4);
    Tree->min.first = min_tmp[0];
    Tree->min.second = min_tmp[1];
}

string sum_min(segment_tree *Tree, int L, int R)
{
    min12 tmp = sum_min_two(Tree, L, R);
    return (tmp.first + tmp.second <= weight) ? "Yes" : "No";
}

int main()
{
    cerr << sizeof(segment_tree) << endl;
    
    cin >> n >> weight;
    
    for (int i = 0; i<n; i++) cin >> mas[i];
    
    segment_tree *Tree_main = new segment_tree; 
    Tree_main = build(0, n-1);

    cin >> k;
    for (int i = 0; i<k; i++) 
    {
        cin >> ch >> a >> b;
        
        if (ch == '1') cout << sum_min(Tree_main, a-1, b-1) << endl;
        else update(Tree_main, a-1, b);
        
    }
}