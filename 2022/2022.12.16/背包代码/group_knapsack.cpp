#include<iostream>//���鱳��
#include<cstring>
using namespace std;
#define maxn 10005
#define M 105
int dp[maxn];//dp[j]��ʾ��ǰ�ѷ�������Ϊj�ı�����õ�����ֵ 
int w[M][M], v[M][M], c[M];//w[i][j]��ʾ��i���j����Ʒ��������v[i][j]��ʾ��i���j����Ʒ�ļ�ֵ,c[i]��ʾ��i����Ʒ������ 
int n, W;//n��ʾn����Ʒ��W��ʾ����������

void group_knapsack(int n,  int W) {//���鱳��
    for(int i = 1; i <= n; i++)
		for(int j = W; j >= 0; j--) 
			for(int k = 1; k <= c[i]; k++)//ö�����ڸ�����Ʒ
				if(j >= w[i][k])
					dp[j] = max(dp[j], dp[j - w[i][k]] + v[i][k]);
}

int main(){
    cout << "��������Ʒ������ n:";
    cin >> n;
    cout << "�����뱳��������W:";
    cin >> W;
    cout << "����������ÿ����Ʒ������,ÿ����Ʒ�������ͼ�ֵ��";
    for(int i = 1; i <= n; i++){ 
        cin >> c[i];
		for(int j = 1; j <= c[i]; j++)
			cin >> w[i][j] >> v[i][j];
	} 
    for(int j = 1; j <= W; j++)//��ʼ����0��Ϊ0
        dp[j] = 0;
    group_knapsack(n, W);
    cout << "װ�뱳��������ֵΪ:" << dp[W] << endl;
    //����dp[]������
    for(int j = 1; j <= W; j++)
        cout << dp[j] << "  ";
    cout << endl;
    return 0;
}
