//多重背包问题 
int n, W;
int w[MAX_N], v[MAX_N], m[MAX_N];

int dp[MAX_W + 1];   //DP数组（循环使用压缩空间，滚动数组） 
int deq[MAX_W + 1];   //双端队列（保存数组下标） 
int deqv[MAX_W + 1];  //对应双端队列的值——保存值）
 
void solve(){
	for (int i = 0; i < n; i++) {
		for (int a = 0; a < w[i]; a++) {
			int head = 0, tail = 0;  //双端队列的头部和尾部
			for (int j = 0; j * w[i] + a < W; j++) {
				//向双端队列的末尾加入 j
				int val = dp[j*w[i] + a] - j * v[i];
				while (head < tail && deqv[t-1] <= val) tail--;
				deq[tail] = j;
				deqv[tail++] = val;
				//从双端队列的头部取出 t
				dp[j * w[i] + a] = deqv[s] + j * v[i];
				if (deq[s] == j - m[i]) head++;				 
			}
		}
	}
	printf("%d\n",dp[W]);
}

 
