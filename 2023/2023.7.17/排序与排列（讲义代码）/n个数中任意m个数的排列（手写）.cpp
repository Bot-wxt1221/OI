#include<bits/stdc++.h>
using namespace std;
int a[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
bool vis[20];        //��¼��i�����Ƿ��ù�
int n, m, b[20];           //���ɵ�һ��ȫ����
void dfs(int s, int t) {
	if(s == m) {                      //�ݹ����������һ��m����������
		for(int i = 0; i < m; ++i)  cout << b[i] << " ";    //���һ������
		cout<<endl;
		return;
	}
	for(int i = 0; i < t; i++)
		if(!vis[i]) {
			vis[i] = true;
			b[s] = a[i];
			dfs(s+1, t);
			vis[i] = false;
		}
}
int main() {
	cin >> n >> m;
	dfs(0,n);     //ǰn������ȫ����
	return 0;
}

