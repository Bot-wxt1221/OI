#include<iostream>//分组背包
#include<cstring>
using namespace std;
#define maxn 10005
#define M 105
int dp[maxn];//dp[j]表示当前已放入容量为j的背包获得的最大价值 
int w[M][M], v[M][M], c[M];//w[i][j]表示第i组第j个物品的重量，v[i][j]表示第i组第j个物品的价值,c[i]表示第i组物品的数量 
int n, W;//n表示n组物品，W表示背包的容量

void group_knapsack(int n,  int W) {//分组背包
    for(int i = 1; i <= n; i++)
		for(int j = W; j >= 0; j--) 
			for(int k = 1; k <= c[i]; k++)//枚举组内各个物品
				if(j >= w[i][k])
					dp[j] = max(dp[j], dp[j - w[i][k]] + v[i][k]);
}

int main(){
    cout << "请输入物品的组数 n:";
    cin >> n;
    cout << "请输入背包的容量W:";
    cin >> W;
    cout << "请依次输入每组物品的数量,每组物品的重量和价值：";
    for(int i = 1; i <= n; i++){ 
        cin >> c[i];
		for(int j = 1; j <= c[i]; j++)
			cin >> w[i][j] >> v[i][j];
	} 
    for(int j = 1; j <= W; j++)//初始化第0行为0
        dp[j] = 0;
    group_knapsack(n, W);
    cout << "装入背包的最大价值为:" << dp[W] << endl;
    //测试dp[]数组结果
    for(int j = 1; j <= W; j++)
        cout << dp[j] << "  ";
    cout << endl;
    return 0;
}
