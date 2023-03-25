#include <iostream>
#include <cstdio>
using namespace std;
bool dp[105][105];
char ans[105][105];
int main(){
	freopen("mine.in","r",stdin);
	freopen("mine.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char a;
			cin>>a;
			if(a=='*'){
				dp[i][j]=1;
			}else{
				dp[i][j]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(dp[i][j]==1){
				ans[i][j]='*';
			}else{
				int a=dp[i-1][j-1]+dp[i-1][j+1]+dp[i-1][j]+dp[i][j-1]+dp[i][j+1]+dp[i+1][j-1]+dp[i+1][j]+dp[i+1][j+1];
				ans[i][j]=char(a+'0');
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<ans[i][j];
		}
		cout<<endl;
	}
	return 0;
}
