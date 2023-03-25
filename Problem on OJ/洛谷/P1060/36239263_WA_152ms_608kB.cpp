#include <iostream>
using namespace std;
int dp[30005][35];
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
        p[i].w=(p[i].w)*(p[i].v);
    }
    for(int i=1;i<=m;i++){
        for(int j=n;j>=0;j--){
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-p[i].v]+p[i].w);
        }
    }
    cout<<dp[n][m];
}