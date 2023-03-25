#include <iostream>
using namespace std;
int dp[20005][20005];
int main(){
    int m,n;
    cin>>n>>m;
    int *p=new int[n+5];
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-p[i]]+p[i]);
        }
    }
    cout<<m-dp[n-1][m];
}