#include<iostream>//���ر��� 
#include<cstring>
using namespace std;
#define maxn 10005
#define M 105
int dp[maxn],num[maxn];//dp[j]��ʾ��ǰ�ѷ�������Ϊj�ı�����õ�����ֵ,num[j]ͳ������ 
int w[M],v[M],c[M];//w[i]��ʾ��i����Ʒ��������v[i]��ʾ��i����Ʒ�ļ�ֵ,c[i]��ʾ��i����Ʒ������ 
int n,W;//n��ʾn����Ʒ��W��ʾ����������

int multi_knapsack1(int n, int W){//������֣����׳�ʱ������ 
    for(int i = 1; i <= n; i++)
    	for(int k = 1; k <= c[i]; k++)//��һ��ѭ�� 
			for(int j = W; j >= w[i]; j--)
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
	return dp[W];
}

int multi_knapsack2(int n, int W) { //�����Ʋ�� 
    for(int i = 1; i <= n; i++) {
		if(c[i] * w[i] >= W) {//ת����ȫ����
            for(int j = w[i]; j <= W; j++)
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
        else {
            for(int k = 1; c[i] > 0; k <<= 1) { //�����Ʋ��
	            int x = min(k, c[i]);
	            for(int j = W; j >= w[i] * x; j--)//ת��01���� 
	                dp[j] = max(dp[j], dp[j - w[i] * x] + x * v[i]);
	            c[i] -= x;
        	} 
    	}
	}
	return dp[W];
}

int multi_knapsack3(int n, int W) {//�����Ż� 
	for(int i = 1; i <= n; i++) {
        memset(num, 0, sizeof(num));//ͳ������ 
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
    cout << "��������Ʒ�ĸ��� n:";
    cin >> n;
    cout << "�����뱳��������W:";
    cin >> W;
    cout << "����������ÿ����Ʒ������w����ֵv������c, �ÿո�ֿ�:";
    for(int i = 1; i <= n; i++)
        cin >> w[i] >> v[i] >> c[i];
    for(int j = 1; j <= W; j++)//��ʼ����0��Ϊ0
        dp[j] = 0;
    
    cout << "װ�뱳��������ֵΪ:" << multi_knapsack1(n, W) << endl;
    cout << "װ�뱳��������ֵΪ:" << multi_knapsack2(n, W) << endl;
    cout << "װ�뱳��������ֵΪ:" << multi_knapsack3(n, W) << endl;
    //����dp[]������
    for(int j = 1; j <= W; j++)
        cout << dp[j] << "  ";
    cout << endl;
    return 0;
}
