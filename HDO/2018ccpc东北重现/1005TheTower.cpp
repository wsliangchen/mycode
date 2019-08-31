#include <bits/stdc++.h>

using namespace std;
double h,r,x0,yy,a,b,c,t1,t2,z0,v1,v2,v3;
int T;
int main()
{
    scanf("%d",&T);
    for (int id=1; id<=T; id++)
    {
        cin>>r>>h>>x0>>yy>>z0>>v1>>v2>>v3;
        a=h*h*v1*v1+h*h*v2*v2-v3*v3*r*r;
        b=h*h*2*x0*v1+h*h*2*yy*v2+2*h*v3*r*r-2*z0*v3*r*r;
        c=h*h*x0*x0+h*h*yy*yy-h*h*r*r-z0*z0*r*r+r*r*2*h*z0;
        t2=(-b-sqrt(b*b-4*a*c))/2/a;
        printf("Case %d: %.10f\n",id,t2);
    }
}