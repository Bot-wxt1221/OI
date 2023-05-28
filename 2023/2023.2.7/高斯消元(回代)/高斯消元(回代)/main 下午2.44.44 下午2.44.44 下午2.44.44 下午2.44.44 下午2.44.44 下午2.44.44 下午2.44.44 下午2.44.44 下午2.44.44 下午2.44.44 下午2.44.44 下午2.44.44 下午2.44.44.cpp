//
//  main.cpp
//  高斯消元(回代)
//
//  Created by Matthew on 2022/6/4.
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
double a[105][107];
double ans[1005];
double eps=1e-7;
int main(void) {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n+1;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
    {
        int maxi=i;
        for(int j=i+1;j<=n;j++)
            if(fabs(a[j][i])>fabs(a[maxi][i]))
                maxi=j;
        if(fabs(a[maxi][i])<eps)
        {
            printf("No Solution");
            return 0;
        }
        if(i!=maxi)swap(a[i], a[maxi]);
        double now=a[i][i];
        for(int j=i;j<=n+1;j++)
            a[i][j]/=now;
        for(int j=i+1;j<=n;j++)
        {
            now=a[j][i];
            for(int k=i;k<=n+1;k++)
                a[j][k]-=now*a[i][k];
        }
    }
    ans[n]=a[n][n+1];
    for(int i=n-1;i>=1;i--)
    {
        ans[i]=a[i][n+1];
        for(int j=i+1;j<=n;j++)
        {
            ans[i]-=a[i][j]*ans[j];
        }
    }
    for(int i=1;i<=n;i++)
        printf("%.2lf\n",ans[i]);
    return 0;
}
