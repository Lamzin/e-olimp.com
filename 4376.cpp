#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define SIZE 500

int n=1,i,j,g, sum, tmp;
int a[SIZE][SIZE], b[SIZE][SIZE];
bool result;

int main()
{
    while(n)
    {
        scanf("%d", &n);
        if (n)
        {
            result = true;
            for (i = 0; i<n; i++) for (j = 0; j<n; j++) scanf("%d", a[i]+j);
            for (i = 0; i<n; i++) for (j = 0; j<n; j++) scanf("%d", b[i] + j);
            for (i = 0; i<n; i++) for (j = 0; j<n; j++) 
            {   
                scanf("%d", &tmp);
                if (result)
                {
                    sum  = 0;
                    for (g = 0; g<n; g++) sum += a[i][g]*b[g][j];
                    if (sum != tmp) result = false;
                }
            }
            if (result) printf("YES\n");
            else printf("NO\n");
        }
    }
    
    return 0;
}