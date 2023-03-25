#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
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
int ans;
class tree{
	public:
		tree *l,*r;
		char a;
}d[100005];
class node{
	public:
		tree *a;
		int co;
		node();
};
char c[100005];
int conut[300];
node::node(){
	co=0;
	a=NULL;
	return ;
}
char a[100005];
bool operator <(node a,node b){
	return a.co>b.co;
}
tree *alpha[400];
priority_queue<node>b;
void dfs(tree a,int node);
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	while(scanf("%s",a)!=EOF){
		if(a[0]=='E'&&a[1]=='N'&&a[2]=='D'&&a[3]=='\0'){
			return 0;
		}
		printf("%d ",strlen(a)*8);
		memset(conut,0,sizeof(conut));
		for(int i=0;i<strlen(a);i++){
			conut[a[i]]++;
		}
		b=priority_queue<node>();
		memset(d,0,sizeof(d));
		int temp2=0;
		for(int i=1;i<=299;i++){
			if(conut[i]){
				node temp;
				temp.co=conut[i];
				c[conut[i]]=i;
				temp2++;
				alpha[i]=&d[temp2];
				d[temp2].a=i;
				temp.a=alpha[i];
				b.push(temp);
			}
		}
		while(b.size()>1){
			node a=b.top();
			b.pop();
			node c=b.top();
			b.pop();
			temp2++;
			d[temp2].l=a.a;
			d[temp2].r=c.a;
			node temp;
			temp.co=a.co+c.co;
			temp.a=&d[temp2];
			b.push(temp);
		}
		ans=0;
		dfs(d[temp2],0);
		printf("%d %.1llf\n",ans,strlen(a)*8.0/ans);
	}
	return 0;
}
void dfs(tree a,int de){
	if(a.a!=0){
		ans+=(de*conut[a.a]);
		return ;
	}
	dfs(*a.l,de+1);
	dfs(*a.r,de+1);
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
Mo*/


