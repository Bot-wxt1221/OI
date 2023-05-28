#include <iostream>
#include <cstdio>
using namespace std;
#define int long long
const int maxn=1e4+10;
int l[maxn],t[maxn],x[maxn];
int w[maxn],h[maxn],s[maxn];
int ans;
int calc(int n){
	int sum=0;
	for(int i=1;i<=n;++i){    
		if(x[i]<=n){
            sum+=s[i];
			continue; 
		}
//////////////////////////////////
		else if(l[i]>=n){
            sum-=s[i];
			continue;
        }
        else sum=sum+(n-l[i])*h[i]-(x[i]-n)*h[i];         
    }
//    cout<<sum<<endl
    return sum;
}
 //////////////////////////////////
void ask(int l,int r)     
{
     if(l==r) {     
//     	cout<<l<<endl;
         ans=l;
         return;
     }
     int mid=(l+r)/2;
     if(calc(mid)>=0)ask(l,mid); 
     else ask(mid+1,r);
}
//////////////////////////////////
 int r,n;
signed main()
{
	freopen("rectangle.in","r",stdin);
	freopen("rectangle.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>r>>n;
    for(int i=1;i<=n;++i){
        cin>>l[i]>>t[i]>>w[i]>>h[i];
        x[i]=l[i]+w[i],s[i]=w[i]*h[i];
    }
	ask(0,r);
    while(calc(ans)==calc(ans+1)&&ans<r)ans++;
    cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


