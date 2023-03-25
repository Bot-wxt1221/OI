#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
inline int read(){
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
int lcafa[200005];
int lcagetf(int a){
	return a==lcafa[a]?a:lcafa[a]=lcagetf(lcafa[a]);
}
vector<int>ques[200005];
int fa[200005];
int getfa(int a){
	return a==fa[a]?a:fa[a]=getfa(fa[a]);
}
int fir[200005];
int nxt[200005];
int v[200005];
int now;
int op[200005];
int aore[200005];
int bon[200005];
int ans[200005];
int u[200005];
int dep[200005];
void add(int a,int b){
	now++;
	v[now]=b;
	u[now]=a;
	nxt[now]=fir[a];
	fir[a]=now;
	return ;
}
bool vised[200005];
void dfs(int now,int f);
int main(){
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	int n=read(),t;
	t=read();
	for(int i=1;i<=n;i++){
		fir[i]=-1;
		fa[i]=i;
		lcafa[i]=i;
	}
	for(int i=1;i<n;i++){
		int a=read(),b;
		b=read();
		add(a,b);
		add(b,a);
	}
	for(int i=1;i<=t;i++){
		char a;
		scanf("%c",&a);
		if(a=='C'){
			op[i]=1;
			aore[i]=read();
		}else{
			op[i]=2;
			aore[i]=read();
			bon[i]=read();
			ques[aore[i]].push_back(i);
			ques[bon[i]].push_back(i);
		}
	}
	dep[0]=-1;
	dfs(1,0);
	int R=0;
	for(int i=1;i<=t;i++){
		if(op[i]==1){
			fa[getfa(v[aore[i]*2-1])]=fa[getfa(u[aore[i]*2-1])];
		}else{
			if(getfa(aore[i])==getfa(bon[i])){
				int K=dep[aore[i]]+dep[bon[i]]-dep[ans[i]]*2;
				R=(R+(i^K))%998244353;
//				printf("%d\n",K);
			}else{
				R=R^(i+aore[i]+bon[i]);
//				printf("-1\n");
			}
		}
	}
	printf("%d",R);
	return 0;
}
void dfs(int now,int f){
	vised[now]=1;
	dep[now]=dep[f]+1;
	for(int i=fir[now];i!=-1;i=nxt[i]){
		if(v[i]==f){
			continue;
		}
		dfs(v[i],now);
		lcafa[lcagetf(v[i])]=lcagetf(now);
	}
	int siz=ques[now].size();
	for(int i=0;i<siz;i++){
		int temp=ques[now][i];
		int a=lcagetf(aore[temp]);
		int b=lcagetf(bon[temp]);
		if(bon[temp]==now){
			swap(a,b);
		}
		if(vised[aore[temp]]&&vised[bon[temp]]){
			ans[temp]=b;
		}
	}
	return ;
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



