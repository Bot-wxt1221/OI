#include <cstdio>
using namespace std;
int dp[35];
int main(){
    int n;
    scanf("%d",&n);
    dp[1]=dp[2]=1;
    for(int i=3;i<=30;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    for(int i=1;i<=n;i++){
        int temp;
        scanf("%d",&temp);
        printf("%d\n",dp[temp]);
    }
    return 0;
}