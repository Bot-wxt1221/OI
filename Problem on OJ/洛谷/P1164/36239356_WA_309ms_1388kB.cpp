#include <iostream>
using namespace std;
int f[105][10005],a[105];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){//种
        for(int j=1;j<=m;j++){//价格
            if(j==a[i]){
                f[i][j]=f[i-1][j]+1;
            }
            if(j>a[i]){
                f[i][j]=f[i-1][j]+f[i-1][j-a[i]];
            }
            if(j<a[i]){
                f[i][j]=f[i-1][j];
            }
        }
    }
    cout<<f[n][m];
    return 0;
}