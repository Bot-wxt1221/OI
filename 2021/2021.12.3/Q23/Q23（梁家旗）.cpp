#include <bits/stdc++.h>
using namespace std; 
int cnt=0;
int vis[10005];
void dfs(int money,int step){
	if(money<=0) return;//如果钱被输光了，则不能继续赌博 
	if(step==25) {//如果到达边间，则找完一种情况，计数器增加1 
		cnt++;return;
	}
	for(int k=-1;k<=1;k+=2){//-1为输，1为赢 
		if(vis[step]==0){
			vis[step]=1;
			money+=k;
			dfs(money,step+1);
			money-=k;//回溯 
			vis[step]=0;
		}
	}
}
int main(){
	dfs(10,1);cout<<cnt<<endl;
}
