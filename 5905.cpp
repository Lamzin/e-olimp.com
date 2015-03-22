#include <stdio.h>
#include <math.h>

int n;
double a,b;

double abs(double x)
{
    return (x > 0) ? x : -x; 
}

int main()
{
    scanf("%d\n%lf %lf", &n, &a, &b);
        
    for (int k = 0; k < n; k++)
    {
        if (abs(cos(2*M_PI*k/n) - a) < 0.000001 && abs(sin(2*M_PI*k/n) - b) < 0.000001) 
        {
            printf("%d\n", k);
            break;
        }
    }
}