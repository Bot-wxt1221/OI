//��Ѽӷ����ʽ
/*
����������
��һ����1..9��ɵ����ִ�(����Ϊ n)��������� m���Ӻţ������ţ����뵽������ִ��У�
�ڸ��ֿ����γɵĿɼ�����ʽ�У�ֵ��С���Ǹ����ʽ��ֵ�Ƕ��٣�

�����ʽ��
�������ݣ�ÿ�������������£� 
�����һ�������� m��
����ڶ����ǳ���Ϊ n �����ִ��� 

�����ʽ��
��ÿ�����ݣ����һ�У�����С�ӷ����ʽ��ֵ��

��������1��
1
1234

�������1��
46

��������2��
2
123456
1
123456
4
12345

�������2��
102
579
15

���ݷ�Χ��
1 <= n <= 50
0 <= m <= n - 1
*/ 

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 55; 
struct BIG_INT {  //��������������� +�� <
	int len;  //����������
	int a[MAXN]; //�������洢����
	BIG_INT() {  //Ĭ�ϳ�ʼ��, ����һ��������ʱĬ�ϵĳ�ʼ��ֵ 
		len = 1;
		memset(a, 0, sizeof(a));
	} 
	BIG_INT(const char *str, int L) { //ָ�������ĳ�ʼ������������Ϊ L �����ִ�ת��Ϊ��Ӧ�Ĵ����� 
		memset(a, 0, sizeof(a));
		len = L;
		for(int i = 0; i < len; i++) {
			a[L - i - 1] = str[i] - '0';
		} 
	}
	//���ش������ӷ��� +
	BIG_INT operator + (const BIG_INT &x) const {
		int MAX_LEN = max(len, x.len); //�����ͱ������ĳ��ȣ�ȡ��ĳ���  
		int c = 0;  //��λ 
		BIG_INT result;
		result.len = MAX_LEN;
		for(int i = 0; i < MAX_LEN; i++) {
			result.a[i] = a[i] + x.a[i] + c;
			c = result.a[i] / 10;
			result.a[i] %= 10;
		} 
		if(1 == c) { //�������λ��λ 
			result.len = MAX_LEN + 1;
			result.a[MAX_LEN] = c;
		} 
		return result;	
	} 
	//���ش������Ƚϣ� <
	bool operator < (const BIG_INT &x) const {
		if(len > x.len) return false;
		else if(len < x.len) return true;
		else {
			for(int i = len - 1; i >= 0; i--) {
				if(a[i] < x.a[i]) return true;
				else if(a[i] > x.a[i]) return false;
			}
			return false;
		}		
	}  	
};

char num_str[MAXN]; 
BIG_INT num[MAXN][MAXN];  //num[i][j]--- ��ʾ num_str[i]~ num_str[j]���ִ���Ӧ�Ĵ����� 
BIG_INT dp[MAXN][MAXN];  //dp[i][j]--- i���Ӻŷŵ�ǰj�������м䣬���ܵõ�����ѱ��ʽ��ֵ
//dp���̣� dp[i][j] = min{dp[i-1][k] + num[k+1][j]} , i <= k < j;
BIG_INT INF;  //��������� 

int main() {
	freopen("add.in", "r", stdin);
	freopen("add.out", "w", stdout);
	int m;  //�ӷ����� 	
	INF.len = MAXN - 1;
	INF.a[MAXN - 2] = 1; //��ʼ��������ֵ 
		
	while(cin >> m) { 
		cin >> num_str;
		int n = strlen(num_str);
		//��ʼ�� num[i][j]
		for	(int i = 1; i <= n; i++) {
			for(int j = i; j <= n; j++) {
				num[i][j] = BIG_INT(num_str + i - 1, j - i + 1);
				/*
				cout << i << "~" << j << " : "; 
				for(int k = num[i][j].len - 1; k >= 0; k--)
    				cout << num[i][j].a[k];
				cout << endl;	
				*/			
			}
		}
		
		//��ʼ��dp�߽磺dp[0][j] = ǰ j �����ִ���Ӧ�Ĵ�����
		for(int j = 1; j <= n; j++) {
			dp[0][j] = BIG_INT(num_str, j);
		} 
		//���ƴ�� dp[i][j]
		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= n; j++) {
				if(j < i + 1) { // �����ڼӺŵ����������ָ��������״̬����ʼ��Ϊ����� 
					dp[i][j] = INF; 
				}
				else { //������ѱ��ʽ��ֵ 
					BIG_INT MIN = INF;
					for(int k = i; k < j; k++) {
						MIN = min(MIN, dp[i - 1][k] + num[k + 1][j]);
					} 
					dp[i][j] = MIN;
				}
			}
		} 
		//��� dp[m][n]
		for(int i = dp[m][n].len - 1; i >= 0; i--)
    		cout << dp[m][n].a[i];
		cout << endl;	
		
	}
	return 0;
}

