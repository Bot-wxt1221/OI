#include <iostream>
#include <cstdio>
#include <deque>
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
deque<int>to[1000005];
int fa[1000005];
int temp[1000005];
bool broke[1000005];
int getfa(int x){
	return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n-1;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		to[a].push_back(b);
		to[b].push_back(a);
	}
	int k;
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		scanf("%d",&temp[i]);
		broke[temp[i]]=1;
	}
	int now=0;
	for(int i=0;i<=n-1;i++){
        for(int j=0;j<to[i].size();j++){
            if(broke[i]==0&&broke[to[i][j]]==0&&getfa(i)!=getfa(to[i][j])){
                fa[getfa(to[i][j])]=fa[getfa(i)];
                now--;
            }
        }
	}
	for(int i=0;i<n;i++){
        if(!broke[i]){
            now++;
        }
	}
	for(int i=k;i>=1;i--){
        now++;
        broke[temp[i]]=0;
		for(int j=0;j<to[temp[i]].size();j++){
			if(getfa(to[temp[i]][j])==getfa(temp[i])||broke[to[temp[i]][j]]){

			}else{
				now--;
				fa[getfa(to[temp[i]][j])]=getfa(temp[i]);
			}
		}
		temp[i]=now;
	}
	for(int i=1;i<=k;i++){
		printf("%d\n",temp[i]);
	}
	printf("%d",n-k);
	return 0;
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



