#include<iostream>
#include<string>
using namespace std;
string s;
long long man,f[41][41]={{0}},n,k;
long long cs(int ks,int js)
{
    long long sum=0,t=1;
    for(int i=js;i>=ks;i--){sum=sum+(s[i]-'0')*t,t=t*10;}
    return sum;
}
int main()
{
    cin>>n>>k>>s;
    for(int i=0;i<n;i++){f[0][i]=cs(0,i);}
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int h=j;h>=i;h--)
            {
                f[i][j]=max(f[i][j],f[i-1][h-1]*cs(h,j));
            }
        }
    }
    cout<<f[k][n-1];
}