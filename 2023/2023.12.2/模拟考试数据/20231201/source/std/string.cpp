#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n,k;cin>>n>>k;
    if(!k) return cout<<0,0;
    if(n&1) cout<<1ll*(n/2+1)*(n/2+1)<<'\n';
    else  cout<<1ll*n/2*(n/2+1)<<'\n';
    int now=n/2+(n&1)+k/2;k--;
    for(int i=1;i<=n;i++)
    {
        if(k-->0||i==now) cout<<1<<' ';
        else cout<<0<<' ';
    }
}
