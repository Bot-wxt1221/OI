//���ر������� 
int n, W;
int w[MAX_N], v[MAX_N], m[MAX_N];

int dp[MAX_W + 1];   //DP���飨ѭ��ʹ��ѹ���ռ䣬�������飩 
int deq[MAX_W + 1];   //˫�˶��У����������±꣩ 
int deqv[MAX_W + 1];  //��Ӧ˫�˶��е�ֵ��������ֵ��
 
void solve(){
	for (int i = 0; i < n; i++) {
		for (int a = 0; a < w[i]; a++) {
			int head = 0, tail = 0;  //˫�˶��е�ͷ����β��
			for (int j = 0; j * w[i] + a < W; j++) {
				//��˫�˶��е�ĩβ���� j
				int val = dp[j*w[i] + a] - j * v[i];
				while (head < tail && deqv[t-1] <= val) tail--;
				deq[tail] = j;
				deqv[tail++] = val;
				//��˫�˶��е�ͷ��ȡ�� t
				dp[j * w[i] + a] = deqv[s] + j * v[i];
				if (deq[s] == j - m[i]) head++;				 
			}
		}
	}
	printf("%d\n",dp[W]);
}

 
