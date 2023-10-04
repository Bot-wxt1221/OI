//多重背包问题 ,按1，2，4，...，2^k，a的个数分组，01背包解决, O(nWlogm) 
int dp[MAX_W + 1];   //DP数组（循环使用压缩空间，滚动数组） 

void solve(){
	for (int i = 0; i < n; i++) {
			int  num = m[i];
			for (int k = 1; num > 0; k <<= 1){
				int mul = min(k,num);
				for (int j = W; j >= w[i] * mul; j--){
					dp[j] = max(dp[j], dp[j - w[i] * mul] + v[i] * mul);
				}
				num -= mul;
			}
		}
		printf("%d\n",dp[W]);
}

 
