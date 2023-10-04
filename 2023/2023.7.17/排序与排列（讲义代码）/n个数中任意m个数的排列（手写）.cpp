#include<bits/stdc++.h>
using namespace std;
int a[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
bool vis[20];        //记录第i个数是否用过
int n, m, b[20];           //生成的一个全排列
void dfs(int s, int t) {
	if(s == m) {                      //递归结束，产生一个m个数的排列
		for(int i = 0; i < m; ++i)  cout << b[i] << " ";    //输出一个排列
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
	dfs(0,n);     //前n个数的全排列
	return 0;
}

