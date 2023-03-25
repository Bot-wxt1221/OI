#include <iostream>
#include <cstdio>
#include <algorithm>
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
int stack[500005];
int top=0;
int aa[500005];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read(),ans=0;
	for(int i=1;i<=n;i++){
		aa[i]=read();
	}
	stack[top++]=aa[1];
	for(int i=2;i<=n;i++){
		if(stack[top-1]>aa[i]){
			stack[top++]=aa[i];
			ans++;
			continue;
		}
		int l=0,r=top-1,mid=(l+r+1)/2;
		while(l<r){
			if(stack[mid]<=aa[i]){
				l=mid;
			}else{
				r=mid+1;
			}
			mid=(l+r+1)/2;
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
