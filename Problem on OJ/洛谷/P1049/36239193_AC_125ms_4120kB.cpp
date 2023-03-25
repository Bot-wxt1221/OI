#include <iostream>
using namespace std;
int dp[20005][20005];
int main(){
    int m,n;
    cin>>m>>n;
    int *p=new int[n+5];
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j;j--){
        	if(j-p[i]<0){
        		 dp[i][j]=dp[i-1][j];
        		 continue;
			}
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-p[i]]+p[i]);
        }
    }
    cout<<m-dp[n][m];
}