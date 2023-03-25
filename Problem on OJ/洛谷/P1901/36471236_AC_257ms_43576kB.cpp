#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int h[1000005];
int v[1000005];
int ans[1000005];
int lMax[1000005];
int rMax[1000005];
int St[1000005];
int top=0;
signed main(){
//	freopen("a.in","r",stdin);
//	freopen(".out","w",stdout);
	int n;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&h[i],&v[i]);
	}
	for(int i=1;i<=n;i++){
		while(top>0&&h[St[top-1]]<=h[i])	top--;
		if(top==0)	lMax[i]=0;
		else lMax[i]=St[top-1];
		St[top++]=i;
	}
	top=0;
	for(int i=n;i>=1;i--){
		while(top>0&&h[St[top-1]]<=h[i])	top--;
		if(top==0)	rMax[i]=n+1;
		else rMax[i]=St[top-1];
		St[top++]=i;
	}
	for(int i=1;i<=n;i++){
		if(h[lMax[i]]>h[i]&&lMax[i]!=0){
			ans[lMax[i]]+=v[i];
//			cout<<lMax[i]<<' '<<ans[lMax[i]]<<' ';
		}
		if(h[rMax[i]]>h[i]&&rMax[i]!=n+1){
			ans[rMax[i]]+=v[i];
//			cout<<rMax[i]<<' '<<ans[rMax[i]]<<' ';
		}
	}
	int ans2=0;
	for(int i=1;i<=n;i++){
//		cout<<lMax[i]<<' '<<rMax[i]<<endl;
		ans2=max(ans2,ans[i]);
	}
	cout<<ans2;
	return 0;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/
