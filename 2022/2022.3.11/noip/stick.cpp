
/*
按长度为主要关键字，重量为此要关键字，排序，在贪心（可以调换） 
*/
#include <iostream>
#include <cstdio>
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
int l[1005],w[1005];
bool vised[1005];
int main(){
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		l[i]=read();
		w[i]=read();
	}
	int choose=0,ans=0;
	for(int i=1;i<=n;i++){//排序 
		for(int j=i+1;j<=n;j++){
			if(w[i]==w[j]?l[i]>l[j]:w[i]>w[j]){
				swap(l[i],l[j]);
				swap(w[i],w[j]);
			}
		}
	}
	while(choose<n){//选择 
		ans++;
		int maxl=0,maxw=0;
		for(int i=1;i<=n;i++){
			if(vised[i]){
				continue;
			}
			if(maxl<=l[i]&&maxw<=w[i]){//贪心 
				maxl=l[i];
				maxw=w[i];
				choose++;
				vised[i]=1;
			}
		}
	}
	cout<<ans; 
	return 0;
}

