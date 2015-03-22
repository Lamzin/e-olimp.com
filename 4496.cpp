#include <fstream>
#include <iostream> 

using namespace std;

fstream in("input.txt", ios:: in), out("output.txt", ios:: out);

#define cin in
#define cout out
#define SIZE 1000000
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
    int pos_left, pos_right;

    ll sum;
    
    segment_tree *left, *right;
};

segment_tree* build(ll L, ll R)
{
    segment_tree *Tree = new segment_tree;

    if (L == R)
    {
        Tree->sum = (L >= n) ? INF : mas[L];
        
        Tree->pos_left = Tree->pos_right = L;
        Tree->left = Tree->right = NULL;
        return Tree;
    }
    
    int M = (L + R) / 2;
    
    Tree->left = build(L, M);
    Tree->right = build(M+1, R);
    Tree->pos_left = L;
    Tree->pos_right = R;

    Tree->sum = Tree->left->sum + Tree->right->sum;
    
    return Tree;
}

ll sum(segment_tree *Tree, ll L, ll R)
{
    if (L < Tree->pos_left) L = Tree->pos_left;
    if (R > Tree->pos_right) R = Tree->pos_right;
    if (L > R) return 0;
    
    if (Tree->pos_left == L && Tree->pos_right == R) return Tree->sum;
    
    return sum(Tree->left, L, R) + sum(Tree->right, L, R);
}

void update(segment_tree *Tree, ll position, ll value)
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

int count(segment_tree *Tree, ll weight, ll L, ll R)
{
    if (L==R)
    {
        if (sum(Tree, L, R) > weight) return 0;
        else return 1;
    }
    
    ll sum_tmp = sum(Tree, L, R);
    if (sum_tmp<= weight) return R-L+1;
    
    ll M = (L+R)/2, weight_L, weight_R;
    
    weight_L = sum(Tree, L, M);
    
    if (weight_L > weight) return count(Tree, weight, L, M);
    else return (M-L+1) + count(Tree, weight - weight_L, M+1, R);
}

int main()
{
    cin >> n;
    
    for (ll i = 0; i<n; i++) cin >> mas[i];
    
    segment_tree *Tree_main = new segment_tree; 
    Tree_main = build(0, SIZE-1);

    cin >> k;
    for (ll i = 0; i<k; i++) 
    {
        cin >> a;
        
        if (a == 1) 
        {
            cin >> b;
            cout << count(Tree_main, b, 0, n-1) << endl;
        }
        else
        {
            cin >> a >> b;
            update(Tree_main, a-1, b);
        }
    }
}