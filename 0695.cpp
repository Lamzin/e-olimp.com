#include <fstream>
#include <iostream> 

using namespace std;

fstream in("input.txt", ios:: in), out("output.txt", ios:: out);

#define cin in
#define cout out
#define SIZE 100000
#define INF 1000000000000000000
#define ll long long
#define MOD1 12345
#define MOD2 23456

ll n, k, a, b, mas[SIZE];

ll min(ll a, ll b)
{
    return (a < b) ? a : b;
}

ll max(ll a, ll b)
{
    return (a > b) ? a : b;
}

struct segment_tree
{
    ll pos_left, pos_right;

    ll min, max;
    
    segment_tree *left, *right;
};

segment_tree* build(ll L, ll R)
{
    segment_tree *Tree = new segment_tree;

    if (L == R)
    {
        Tree->min = Tree->max = mas[L];
        
        Tree->pos_left = Tree->pos_right = L;
        Tree->left = Tree->right = NULL;
        return Tree;
    }
    
    int M = (L + R) / 2;
    
    Tree->left = build(L, M);
    Tree->right = build(M+1, R);
    Tree->pos_left = L;
    Tree->pos_right = R;

    Tree->min = min(Tree->left->min, Tree->right->min);
    Tree->max = max(Tree->left->max, Tree->right->max);
    
    return Tree;
}

ll minimum(segment_tree *Tree, ll L, ll R)
{
    if (L < Tree->pos_left) L = Tree->pos_left;
    if (R > Tree->pos_right) R = Tree->pos_right;
    if (L > R) return INF;
    
    if (Tree->pos_left == L && Tree->pos_right == R) return Tree->min;
    
    return min(minimum(Tree->left, L, R), minimum(Tree->right, L, R));
}

ll maximum(segment_tree *Tree, ll L, ll R)
{
    if (L < Tree->pos_left) L = Tree->pos_left;
    if (R > Tree->pos_right) R = Tree->pos_right;
    if (L > R) return -INF;
    
    if (Tree->pos_left == L && Tree->pos_right == R) return Tree->max;
    
    return max(maximum(Tree->left, L, R), maximum(Tree->right, L, R));
}

void update(segment_tree *Tree, ll position, ll value)
{
    if (Tree->pos_left == Tree->pos_right)
    {
        Tree->min = Tree->max = value;
        return;
    }
    
    if (position < Tree->right->pos_left) update(Tree->left, position, value);
    else update(Tree->right, position, value);

    Tree->min = min(Tree->left->min, Tree->right->min);
    Tree->max = max(Tree->left->max, Tree->right->max);
}

int main()
{
    for (ll i = 1; i<=SIZE; i++) mas[i-1] = (i*i) % MOD1 + (i*i*i) % MOD2;
    
    segment_tree *Tree_main = new segment_tree; 
    Tree_main = build(0, SIZE-1);

    cin >> k;
    for (ll i = 0; i<k; i++) 
    {
        cin >> a >> b;

        if (a > 0) cout << maximum(Tree_main, a-1, b-1) - minimum(Tree_main, a-1, b-1) << endl;
        else if (a < 0) update(Tree_main, -a-1, b);
    }
}