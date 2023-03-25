
/*
排序后一头一尾考虑，使用下标变量进行扫描 
*/
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
int a[30005];
int main(){
	freopen("group.in","r",stdin);
	freopen("group.out","w",stdout);
	int w,n,ans=0,more=w;
	w=read();
	n=read();
	more=w;
	int l=1,r=n;
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);//排序 
	while(l<r){
		if(a[l]+a[r]<=w){//能一起装 
			ans++;
			l++,r--;
		}else{//不能一起装 
			ans++;
			r--;
		}
	}
	if(l==r){
		ans++;//还剩一个 
	}
	cout<<ans;
	return 0;
}

