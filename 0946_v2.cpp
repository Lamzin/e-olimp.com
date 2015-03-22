#include <iostream>
#include <math.h>

using namespace std;

float len(int x1, int y1, int x2, int y2)
{
	return sqrtf((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
int main()
{
	int xa,xb,xc,xd,ya,yb,yc,yd;
	cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd; 
	float p = (len(xa,ya,xb,yb)+len(xa,ya,xd,yd)+len(xb,yb,xc,yc)+len(xc,yc,xd,yd)) / 2;
	//cout.precision(0);
	cout << /*fixed << */ (int)sqrtf( (p-len(xa,ya,xb,yb))*(p-len(xa,ya,xd,yd))*(p-len(xb,yb,xc,yc))*(p-len(xc,yc,xd,yd)) ) << endl;
}