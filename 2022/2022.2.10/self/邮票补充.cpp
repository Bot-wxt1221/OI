#include <iostream>
#include <cstdio>
using namespace std;
int n,_max=0;
bool aa[10000005];
int _max2[10000005];
int vis[10000005];
int vis2[10000005];
void dfs2(int step,int more);
void dfs(int step,int last);
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>n;
	dfs(2,1);
	for(int i=1;i<=n;i++){
		cout<<_max2[i]<<' ';
	}
	cout<<_max;
	return 0;
}
void dfs2(int step,int more){
	if(step==n+1){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=vis2[i]*vis[i];
		}
		aa[ans]=1;
		return ;
	}
	for(int i=0;i<=more;i++){
		vis[step]=i;
		dfs2(step+1,more-i);
	}
	return ;
}
void dfs(int step,int last){
	if(step==n+1){
		vis2[1]=1;
		memset(aa,0,sizeof(aa));
		dfs2(1,n);
		for(int i=1;;i++){
			if(aa[i]==0){
				if(_max<i-1){
					for(int j=1;j<=n;j++){
						_max2[j]=vis2[j];
					}
					_max=i-1; 
				}
			return ;
		}
	}
	}
	for(int i=last+1;i<=last*n+1;i++){
		vis2[step]=i;
		dfs(step+1,i);
	}
	return ;
}
