#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN= 100;
vector<int>Q[MAXN];
int de[MAXN];
int len=0;
int fath[MAXN];
void link(int fa,int so);
int dfs(int n,int de);
int getlca(int x,int y);
int main() {
//	freopen("tree.in","r",stdin);
	int n,fa,so;
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>fa>>so;
		link(fa,so);
	}
	dfs(0,0);
	cout<<len; 
	return 0;
}
void link(int fa,int so){
	Q[fa].push_back(so);
	fath[so]=fa;
}
int dfs(int n,int det){ 
	int mmx;//次长链
	int mx;//最长链 
	de[n]=det;
	for(int i=0;i<Q[n].size();i++){
		int temp=dfs(Q[n][i],det+1);
		if(temp>mx){
			mmx=mx;
			mx=temp;
		}else if(temp>mmx){
			mmx=temp;
		}
		len=max(len,mmx+mx);
		return mx;
	}
}
int getlca(int x,int y){
	while(x!=y){
		if(de[x]>=de[y]){
			x=fath[x];
		}
		else{
		y=fath[y]; 
		}
	return x;
	}
}
