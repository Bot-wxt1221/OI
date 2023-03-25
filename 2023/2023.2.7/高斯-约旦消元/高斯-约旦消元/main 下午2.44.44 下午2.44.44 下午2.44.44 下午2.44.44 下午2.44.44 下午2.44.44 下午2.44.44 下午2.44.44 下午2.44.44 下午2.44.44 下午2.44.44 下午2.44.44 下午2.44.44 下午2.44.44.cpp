//
//  main.cpp
//  高斯-约旦消元
//
//  Created by Matthew on 2022/6/8.
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
double a[105][107];
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
                maxi=i;
        if(fabs(a[maxi][i])<=eps)
        {
            printf("No Solution");
            return 0;
        }
        if(i!=maxi)swap(a[i], a[maxi]);
        for(int j=1;j<=n;++j)
        {
            if(j!=i)
            {
                double temp=a[j][i]/a[i][i];
                for(int k=i+1;k<=n+1;k++)
                {
                    a[j][k]-=a[i][k]*temp;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
        printf("%.2lf\n",a[i][n+1]/a[i][i]);
    return 0;
}
