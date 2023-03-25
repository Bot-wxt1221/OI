#include <iostream>
using namespace std;
const int pre[2][2]={{0,1},{1,0}};
int aa[10][10];
int dp[10][10][10][10];
int _ans=0;
int max(int a,int b,int c,int d){
	return max(max(a,b),max(c,d));
}
int n;
int main(){
	cin>>n;
	int a,b,c;
	do{
		cin>>a>>b>>c;
		aa[a][b]=c;
	}while(a!=0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int i2=1;i2<=n;i2++){
				for(int j2=1;j2<=n;j2++){
					dp[i][j][i2][j2]=max(dp[i-1][j][i2-1][j2],dp[i-1][j][i2][j2-1],dp[i][j-1][i2-1][j2],dp[i][j-1][i2][j2-1])+aa[i][j]+aa[i2][j2];
					if(i==i2&&j==j2){
						dp[i][j][i2][j2]-=aa[i][j];
					}
				}
			}
		}
	}
	cout<<dp[n][n][n][n];
}