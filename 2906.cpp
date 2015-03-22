#include <fstream>

using namespace std;

fstream in("input.txt", ios:: in), out("output.txt", ios:: out);

#define cin in
#define cout out
#define SIZE 50000
#define INF 30000
#define ll long long

int n, k, a, b, mas[SIZE];

struct segment_tree
{
    int pos_left, pos_right;
    
    ll sum;
    
    segment_tree *left, *right;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

segment_tree* build(int L, int R)
{
    segment_tree *Tree = new segment_tree;

    if (L == R)
    {
        Tree->max = mas[L];
        Tree->pos_left = Tree->pos_right = L;
        Tree->left = Tree->right = NULL;
        return Tree;
    }
    
    int M = (L + R) / 2;
    
    Tree->left = build(L, M);
    Tree->right = build(M+1, R);
    Tree->max = max(Tree->left->max, Tree->right->max);
    Tree->pos_left = L;
    Tree->pos_right = R;

    return Tree;
}

ll sum_tree(segment_tree *Tree, int L, int R)
{
    if (L < Tree->pos_left) L = Tree->pos_left;
    if (R > Tree->pos_right) R = Tree->pos_right;
    if (L > R) return -INF;
    
    if (Tree->pos_left == L && Tree->pos_right == R) return Tree->max;
    
    return sum_tree(Tree->left, L, R)+sum_tree(Tree->right, L, R);
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
        cin >> a >> b;
        cout << sum_tree(Tree_main, a-1, b-1) << endl;
    }
}