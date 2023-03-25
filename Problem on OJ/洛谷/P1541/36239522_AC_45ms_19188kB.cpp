#include <iostream>
#include <algorithm>
using namespace std;
int a[500],b[10];
int dp[50][50][50][50];
int main(){
	int n,m,r;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	for(int i=1;i<=m;i++){
		int temp;
		cin>>temp;
		b[temp]++;
	}
	dp[0][0][0][0]=a[1];
	for(int i=0;i<=b[1];i++){
		for(int j=0;j<=b[2];j++){
			for(int d=0;d<=b[3];d++){
				for(int c=0;c<=b[4];c++){
					r=1+i+j*2+d*3+c*4;
					if(i!=0) 
						dp[i][j][d][c]=max(dp[i][j][d][c],dp[i-1][j][d][c]+a[r]);
					if(j!=0)
						dp[i][j][d][c]=max(dp[i][j][d][c],dp[i][j-1][d][c]+a[r]);
					if(d!=0)
						dp[i][j][d][c]=max(dp[i][j][d][c],dp[i][j][d-1][c]+a[r]);
					if(c!=0)
						dp[i][j][d][c]=max(dp[i][j][d][c],dp[i][j][d][c-1]+a[r]);
				}
			}
		}
	}
	cout<<dp[b[1]][b[2]][b[3]][b[4]];
	return 0;
}