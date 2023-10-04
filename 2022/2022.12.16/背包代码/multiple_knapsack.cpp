#include<iostream>//多重背包 
#include<cstring>
using namespace std;
#define maxn 10005
#define M 105
int dp[maxn],num[maxn];//dp[j]表示当前已放入容量为j的背包获得的最大价值,num[j]统计数量 
int w[M],v[M],c[M];//w[i]表示第i个物品的重量，v[i]表示第i个物品的价值,c[i]表示第i个物品的数量 
int n,W;//n表示n个物品，W表示背包的容量

int multi_knapsack1(int n, int W){//暴力拆分，容易超时！！！ 
    for(int i = 1; i <= n; i++)
    	for(int k = 1; k <= c[i]; k++)//多一层循环 
			for(int j = W; j >= w[i]; j--)
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
	return dp[W];
}

int multi_knapsack2(int n, int W) { //二进制拆分 
    for(int i = 1; i <= n; i++) {
		if(c[i] * w[i] >= W) {//转化完全背包
            for(int j = w[i]; j <= W; j++)
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
        else {
            for(int k = 1; c[i] > 0; k <<= 1) { //二进制拆分
	            int x = min(k, c[i]);
	            for(int j = W; j >= w[i] * x; j--)//转化01背包 
	                dp[j] = max(dp[j], dp[j - w[i] * x] + x * v[i]);
	            c[i] -= x;
        	} 
    	}
	}
	return dp[W];
}

int multi_knapsack3(int n, int W) {//数组优化 
	for(int i = 1; i <= n; i++) {
        memset(num, 0, sizeof(num));//统计数量 
        for(int j = w[i]; j <= W; j++) {
            if(dp[j] < dp[j - w[i]] + v[i] && num[j - w[i]] < c[i]){
                dp[j] = dp[j - w[i]] + v[i];
                num[j] = num[j - w[i]] + 1;
            }
        }
    }
    return dp[W];
}

int main() {
    cout << "请输入物品的个数 n:";
    cin >> n;
    cout << "请输入背包的容量W:";
    cin >> W;
    cout << "请依次输入每个物品的重量w、价值v和数量c, 用空格分开:";
    for(int i = 1; i <= n; i++)
        cin >> w[i] >> v[i] >> c[i];
    for(int j = 1; j <= W; j++)//初始化第0行为0
        dp[j] = 0;
    
    cout << "装入背包的最大价值为:" << multi_knapsack1(n, W) << endl;
    cout << "装入背包的最大价值为:" << multi_knapsack2(n, W) << endl;
    cout << "装入背包的最大价值为:" << multi_knapsack3(n, W) << endl;
    //测试dp[]数组结果
    for(int j = 1; j <= W; j++)
        cout << dp[j] << "  ";
    cout << endl;
    return 0;
}
