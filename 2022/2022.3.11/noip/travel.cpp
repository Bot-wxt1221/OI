
/*
���ÿһ�����ֵ���γ�һ�����У������������ֵ 
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
	for(int i=1;i<n;i++){//���һ�����ֵ
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
	for(int i=1;i<n;i++){//�������ֵ  ����ǰ׺������������������ã�����Ҫ������С�����Ǳ��������±���ڼ����±꣬����ֱ�Ӽ�¼ǰ����С�ģ�������������ֵ 
		_ans=max(_ans,he[i]-_min);
		_min=min(_min,he[i]);
	}
	cout<<_ans;
	return 0;
}

