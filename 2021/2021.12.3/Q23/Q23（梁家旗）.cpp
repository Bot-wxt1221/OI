#include <bits/stdc++.h>
using namespace std; 
int cnt=0;
int vis[10005];
void dfs(int money,int step){
	if(money<=0) return;//���Ǯ������ˣ����ܼ����Ĳ� 
	if(step==25) {//�������߼䣬������һ�����������������1 
		cnt++;return;
	}
	for(int k=-1;k<=1;k+=2){//-1Ϊ�䣬1ΪӮ 
		if(vis[step]==0){
			vis[step]=1;
			money+=k;
			dfs(money,step+1);
			money-=k;//���� 
			vis[step]=0;
		}
	}
}
int main(){
	dfs(10,1);cout<<cnt<<endl;
}
