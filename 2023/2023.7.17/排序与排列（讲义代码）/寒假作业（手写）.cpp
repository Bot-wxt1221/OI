#include<bits/stdc++.h>
using namespace std;
int a[20]= {1,2,3,4,5,6,7,8,9,10,11,12,13};
bool vis[20];
int b[20];
int ans=0;
void dfs(int s,int t) {
	if(s==12) {
		if(b[9]*b[10] == b[11])   ans++;
		return;
	}
	if(s==3 && b[0]+b[1]!=b[2]) return; //剪枝
	if(s==6 && b[3]-b[4]!=b[5]) return; //剪枝
	if(s==9 && b[6]*b[7]!=b[8]) return; //剪枝
	for(int i=0; i<t; i++)
		if(!vis[i]) {
			vis[i]=true;
			b[s]=a[i];  //本题不用a[]，改成b[s]=i+1也行
			dfs(s+1,t);
			vis[i]=false;
		}
}
int main() {
	int n=13;
	dfs(0,n); //前n个数的全排列
	cout<<ans;
	return 0;
}

