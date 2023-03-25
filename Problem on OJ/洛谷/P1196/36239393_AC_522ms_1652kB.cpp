#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int siz[30005];
int to[30005];
int fa[30005];
int getfa(int x){
	if(fa[x]==x){
		return x;
	}
	int fac=fa[x];
	fa[x]=getfa(fa[x]);
	to[x]+=to[fac];
	return fa[x];
}
void Union(int x,int y){
	int fx=getfa(x);
	int fy=getfa(y);
	if(fx==fy){
		return ;
	}
	fa[fx]=fy;
	to[fx]=siz[fy];
	siz[fy]+=siz[fx];
	return ;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	for(int i=1;i<=30000;i++){
		siz[i]=1;
		fa[i]=i;
	}
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		char a;
		int b,c;
		cin>>a>>b>>c;
//		cout<<a;
		if(a=='M'){
			Union(b,c);
		}else{
			int fx=getfa(b);
			int fy=getfa(c);
			if(fx!=fy){
				cout<<-1<<endl;
			}else{
				cout<<abs(to[b]-to[c])-1<<endl;
			}
		}
	}
	return 0;
}
