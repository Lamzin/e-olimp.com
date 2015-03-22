#include <fstream>
#include <algorithm>
#include <iostream> 

using namespace std;

fstream in("input.txt", ios:: in), out("output.txt", ios:: out);

#define cin in
#define cout out
#define SIZE 100000
#define INF 30000
#define ll long long

int n, k, a, b;
int mas[SIZE], max_tmp[4];
char ch;

struct max12
{
    int first, second;
    max12(int f, int s)
    {
        first = f;
        second = s;
    }
    max12()
    {
        first = second = 0;
    }
};

struct segment_tree
{
    int pos_left, pos_right;
    
    max12 max;
    
    segment_tree *left, *right;
};

segment_tree* build(int L, int R)
{
    segment_tree *Tree = new segment_tree;

    if (L == R)
    {
        Tree->max.first = mas[L];
        Tree->max.second = 0;
                
        Tree->pos_left = Tree->pos_right = L;
        Tree->left = Tree->right = NULL;
        return Tree;
    }
    
    int M = (L + R) / 2;
    
    Tree->left = build(L, M);
    Tree->right = build(M+1, R);
    Tree->pos_left = L;
    Tree->pos_right = R;

    max_tmp[0] = Tree->left->max.first;
    max_tmp[1] = Tree->left->max.second;
    max_tmp[2] = Tree->right->max.first;
    max_tmp[3] = Tree->right->max.second;

    sort(max_tmp, max_tmp + 4);
    Tree->max.first = max_tmp[3];
    Tree->max.second = max_tmp[2];

    return Tree;
}

max12 sum_max_two(segment_tree *Tree, int L, int R)
{
    max12 max12_tmp;
    
    if (L < Tree->pos_left) L = Tree->pos_left;
    if (R > Tree->pos_right) R = Tree->pos_right;
    if (L > R) return max12_tmp;
    
    if (Tree->pos_left == L && Tree->pos_right == R) return Tree->max;
    
    max12 left_max = sum_max_two(Tree->left, L, R), 
          right_max = sum_max_two(Tree->right, L, R);
    
    max_tmp[0] = left_max.first;
    max_tmp[1] = left_max.second;
    max_tmp[2] = right_max.first;
    max_tmp[3] = right_max.second;

    sort(max_tmp, max_tmp + 4);

    max12_tmp.first = max_tmp[3];
    max12_tmp.second = max_tmp[2];
    
    return max12_tmp;
}

void update(segment_tree *Tree, int position, int value)
{
    if (Tree->pos_left == Tree->pos_right)
    {
        Tree->max.first = value;
        Tree->max.second = 0;
        return;
    }
    
    if (position < Tree->right->pos_left) update(Tree->left, position, value);
    else update(Tree->right, position, value);
    
    max_tmp[0] = Tree->left->max.first;
    max_tmp[1] = Tree->left->max.second;
    max_tmp[2] = Tree->right->max.first;
    max_tmp[3] = Tree->right->max.second;

    sort(max_tmp, max_tmp + 4);
    Tree->max.first = max_tmp[3];
    Tree->max.second = max_tmp[2];
}

int sum_max(segment_tree *Tree, int L, int R)
{
    max12 tmp = sum_max_two(Tree, L, R);
    return tmp.first + tmp.second;
}

int main()
{
    cin >> n;
    for (int i = 0; i<n; i++) cin >> mas[i];
    
    segment_tree *Tree_main = new segment_tree; 
    Tree_main = build(0, n-1);

    cin >> k;
    for (int i = 0; i<k; i++) 
    {
        cin >> ch >> a >> b;
        
        if (ch == 'Q') cout << sum_max(Tree_main, a-1, b-1) << endl;
        else update(Tree_main, a-1, b);
        
    }
}