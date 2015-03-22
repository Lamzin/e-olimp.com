#include <fstream>

using namespace std;

fstream in("input.txt", ios:: in), out("output.txt", ios:: out);

#define cin in
#define cout out
#define SIZE 100000
#define ll long long

int n, k, a, b;
int mas[SIZE];
char ch;

struct segment_tree
{
    int pos_left, pos_right;
    
    ll sum;
    
    segment_tree *left, *right;
};

segment_tree* build(int L, int R)
{
    segment_tree *Tree = new segment_tree;

    if (L == R)
    {
        Tree->sum = mas[L];
        Tree->pos_left = Tree->pos_right = L;
        Tree->left = Tree->right = NULL;
        return Tree;
    }
    
    int M = (L + R) / 2;
    
    Tree->left = build(L, M);
    Tree->right = build(M+1, R);
    Tree->sum = Tree->left->sum + Tree->right->sum;
    Tree->pos_left = L;
    Tree->pos_right = R;

    return Tree;
}

ll sum_tree(segment_tree *Tree, int L, int R)
{
    if (L < Tree->pos_left) L = Tree->pos_left;
    if (R > Tree->pos_right) R = Tree->pos_right;
    if (L > R) return 0;
    
    if (Tree->pos_left == L && Tree->pos_right == R) return Tree->sum;
    
    return sum_tree(Tree->left, L, R)+sum_tree(Tree->right, L, R);
}

void update(segment_tree *Tree, int position, short value)
{
    if (Tree->pos_left == Tree->pos_right)
    {
        Tree->sum = value;
        return;
    }
    
    if (position < Tree->right->pos_left) update(Tree->left, position, value);
    else update(Tree->right, position, value);
    
    Tree->sum = Tree->left->sum + Tree->right->sum;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i<n; i++) cin >> mas[i];
    
    segment_tree *Tree_main = new segment_tree; 
    Tree_main = build(0, n-1);

    for (int i = 0; i<k; i++) 
    {
        cin >> ch >> a >> b;
        
        if (ch == '?') cout << sum_tree(Tree_main, a-1, b-1) << endl;
        else update(Tree_main, a-1, (short)b);
        
    }
}