#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a,b,x,y;
    cin>>x>>a>>y>>b;
    printf("%.2lf\n",1.0*(( x*a-y*b )/(a-b)));
    return 0;
}