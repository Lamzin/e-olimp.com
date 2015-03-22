#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
 {
        int N;
        scanf("%d\n", &N);

        vector < pair< double,double> > polygon(N);

        for(int i=0; i<N; ++i)
                scanf("%lf %lf\n", &polygon[i].first,  &polygon[i].second);

        double res = 0;
        for(int i=0; i<N-1; ++i)
        {
                res += (polygon[i+1].first - polygon[i].first) * 
                        (polygon[i+1].second + polygon[i].second)/2.0;
        }

        res += (polygon[0].first - polygon[N-1].first) * 
                (polygon[0].second + polygon[N-1].second)/2.0;

        printf("%.3lf\n", res);
        return 0;
 }