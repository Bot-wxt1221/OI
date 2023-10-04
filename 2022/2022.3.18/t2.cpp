#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
class node{
	public:
		int a,b;
}a[100005];
bool cmp(node a,node b){
	return (b.a*a.b)>(a.a*b.b);
}
signed main(){
	freopen("t2.in","r",stdin);
	freopen("t2.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b;
	}
	sort(a+1,a+n+1,cmp);
	int ans=0;
	int wait=0;
	for(int i=1;i<=n;i++){
		wait+=a[i].a;
		ans+=wait*a[i].b;
	}
	printf("%lld",ans);
	return 0;
}

