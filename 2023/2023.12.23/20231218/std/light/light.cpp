#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
const ll MOD=1000000007,inv2=500000004;
ll prime[1000005],num,sp[1000005];
ll n,Sqr,tot,g[1000005],w[1000005],ind1[1000005],ind2[1000005];
bool flag[1000005];
void pre(ll n)
{
    flag[1]=1;
    for(int i=1;i<=n;i++)
    {
        if(!flag[i])
        {
            prime[++num]=i;
            sp[num]=(sp[num-1]+1)%MOD;
        }
        for(int j=1;j<=num&&prime[j]*i<=n;j++)
        {
            flag[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}
ll S(ll x,int y)
{
    if(prime[y]>=x)return 0;
    ll k=x<=Sqr?ind1[x]:ind2[n/x];
    ll ans=(sp[y]-g[k]+MOD)%MOD;
    for(int i=y+1;i<=num&&prime[i]*prime[i]<=x;i++)
    {
        ll pe=prime[i];
        for(int e=1;pe<=x;e++,pe=pe*prime[i])
        {
            ans=(ans-(S(x/pe,i)+(e!=1))+MOD)%MOD;
        }
    }
    return ans%MOD;
}
int main()
{
	freopen("light.in", "r", stdin);
	freopen("light.out", "w", stdout);
    scanf("%lld",&n);
    Sqr=(ll)sqrt(n);
    pre(Sqr);
    for(ll i=1;i<=n;)
    {
        ll j=n/(n/i);
        w[++tot]=n/i;
        g[tot]=(w[tot]-1)%MOD;
        if(n/i<=Sqr)ind1[n/i]=tot;
        else ind2[n/(n/i)]=tot;
        i=j+1;
    }
    for(int i=1;i<=num;i++)
    {
        for(int j=1;j<=tot&&prime[i]*prime[i]<=w[j];j++)
        {
            ll k=w[j]/prime[i]<=Sqr?ind1[w[j]/prime[i]]:ind2[n/(w[j]/prime[i])];
            g[j]=(g[j]-g[k]+sp[i-1]+MOD)%MOD;
        }
    }
    printf("%lld\n",(n-S(n,0)-1+MOD)*inv2%MOD);
    return 0;
}
