#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int read(){
	int x=0,f=1;char c=getchar();
	if(c==EOF){
		return -1;
	}
	while(c<'0'||c>'9'){
		c=='-'?f=-1:1;
		c=getchar();
		if(c==EOF){
			return -1;
		}
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
		if(c==EOF){
			return -1;
		}
	}
	return f*x;
}
priority_queue<int>a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,k;
	n=read();k=read();
	while((n!=-1)&&(k!=-1)){
		a=priority_queue<int>();//清空 
		for(int i=1;i<=n;i++){
			char aa[100];
			scanf("%s",&aa);
			if(aa[0]=='I'){
				int temp; 
				temp=read();
				if(a.size()<k){
					a.push(-temp);
				}else{ 
					if(-a.top()<temp){
						a.pop();
						a.push(-temp);
					}
				}
			}else{
				printf("%d\n",-a.top());
			}
		}
		n=read();k=read();
	}
	return 0;
}
/*
Anything about this program:
Type:
	例题 
Description:
	小明和小宝正在玩一个简单的数字游戏。小明在每轮中可以选择写下一个数，或者问小宝第
k大的数是什么。因为小明写的数字太多，小宝被问的头晕眼花。现在，请你试着帮助小宝。

Example:
	1:
		In:
			number2.in 
		Out:
			number2.out
维护前k个数的单调序列 set效率较低 
*/

