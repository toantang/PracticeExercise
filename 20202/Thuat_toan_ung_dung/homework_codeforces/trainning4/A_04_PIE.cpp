#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const double PI = 3.14159265358979323846;
int x,y;
double a[10001];
double Max(double x,double y)
{
    if(x>=y)
    return x;
    else return y;
}
double mid(double m)
{
    int sum=0;
    for(int i=1;i<=x;i++)
    {
        sum=floor(sum+a[i]/m);
    }
    return sum>=(y+1);
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        cin>>x>>y;
        double max=-1;
        for(int i=1;i<=x;i++)
        {
            cin>>a[i];
            a[i]=a[i]*a[i]*PI;
            max=Max(max,a[i]);
        }
        double l=0,r=max;
        while(r-l>1e-4)
        {
            double m=(l+r)/2;
            if (mid(m)) l=m;
            else r=m;
        }
        printf("%.6lf\n",l);
    }
    return 0;
}