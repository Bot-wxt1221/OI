#include <iostream>
using namespace std;
int dp[30005][30];
class wu{
    public:
        int v;
        int w;
        wu(){
            v=0,w=0;
        }
};
wu p[35];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>p[i].v>>p[i].w;
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            dp[i][j]=max(dp[i][j-1],dp[i-p[i].v][j-1]+p[i].w*p[i].v);
        }
    }
    cout<<dp[n][m];
}