
/*
求出每一列最大值，形成一个数列，答案是区间最大值 
*/
#include <iostream>
#include <cstdio>
#include <vector>
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
int a[105][20005];
int he[20005];
int vis[20005];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int m=read();
	int n=read();
	for(int i=1;i<=m;i++){
		for(int j=1;j<n;j++){
			a[i][j]=read();
		}
	}
	int size=0;
	for(int i=1;i<n;i++){//求出一列最大值
		int _max=-1000;
		for(int j=1;j<=m;j++){
			_max=max(_max,a[j][i]);
		}
		he[i]=he[i-1]+_max;
		if(_max>0){
			vis[size++]=i;
		}
	}
	int _ans=-20001000,_min=he[0];
	for(int i=1;i<n;i++){//区间最大值  由于前缀和是由两个数相减而得，减数要尽可能小，但是被减数的下标大于减数下标，所以直接记录前面最小的，在相减更新最大值 
		_ans=max(_ans,he[i]-_min);
		_min=min(_min,he[i]);
	}
	cout<<_ans;
	return 0;
}

