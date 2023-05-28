#include <iostream>
#include <cstdio>
#define MAXN 1000
using namespace std;
int tot=0;
int vis[MAXN+5];
int n; 
void dfs(int step,int last,int more);
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>n;
	dfs(0,1,n);
	cout<<"total="<<tot;
	return 0;
}
void dfs(int step,int last,int more){
	if(more==0){
		tot++;
		cout<<n<<"=";
		for(int i=1;i<step;i++){
			cout<<vis[i]<<'+';
		}
		cout<<vis[step];
		cout<<endl;
		return ;
	}
	for(int i=last;i<=min(more,n-1);i++){
		vis[step+1]=i;
		dfs(step+1,i,more-i);
	}
	return ;
}
