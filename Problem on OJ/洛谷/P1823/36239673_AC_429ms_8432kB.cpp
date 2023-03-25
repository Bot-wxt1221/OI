#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		c=='-'?f=-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f*x;
}
int stack[5000005];
int top=0;
int aa[5000005];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".in","w",stdout);
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&aa[i]);
	}
	stack[top++]=aa[1];
	for(int i=2;i<=n;i++){
		if(stack[top-1]>aa[i]){
			stack[top++]=aa[i];
			ans++;
			continue;
		}
		int l=1,r=top,mid=(l+r)>>1;
		while(l<r)
           {
               mid=(l+r)>>1;
               if(r==l+1)mid=r;
               if(aa[i]>=stack[mid-1])r=mid-1;
               else l=mid;
            
		}
		ans+=(top-l)+1;
		while(top!=0&&stack[top-1]<aa[i]){
			top--;
		}
		stack[top++]=aa[i];
	}
	cout<<ans;
	return 0;
}
