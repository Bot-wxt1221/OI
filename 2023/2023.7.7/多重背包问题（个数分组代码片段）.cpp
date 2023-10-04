//���ر������� ,��1��2��4��...��2^k��a�ĸ������飬01�������, O(nWlogm) 
int dp[MAX_W + 1];   //DP���飨ѭ��ʹ��ѹ���ռ䣬�������飩 

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

 
