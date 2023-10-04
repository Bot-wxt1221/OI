#include <iostream>
#include <cstdio>
using namespace std;
int read(){
	char a=getchar();
	int x=0,f=1;
	while('0'>a||a>'9'){
		f=(a=='-'?-1:1);
		a=getchar();
	}
	while(a<='9'&&'0'<=a){
		x=(x<<3)+(x<<1)+(a^'0');
		a=getchar();
	}
	return f*x;
}
int Stack[100005];
int top=0;
int Q[100005];
int r1=0,l1=0;
int Q2[100005];
int r2=0,l2=0;
bool book[100005];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n,temp;
	n=read();
	for(int i=1;i<=n;i++){
		Q[l1++]=read();
	}
	for(int i=1;i<=n;i++){
		Q2[l2++]=read();
	}
	while((l1!=r1)&&(l2!=r2)){
		int now=Q[r1];
		r1++;
		if(book[now]){
			book[now]=0;
			Q[l1++]=now;
			while(top>0&&Stack[top-1]!=now){
				Q[l1++]=Stack[top-1];
				book[Stack[top-1]]=0; 
				top--;
			}
			top--;
			Q[l1++]=Stack[top];
		}else{
			Stack[top++]=now;
			book[now]=1;
		}
		now=Q2[r2];
		r2++;
		if(book[now]){
			book[now]=0;
			Q2[l2++]=now;//第一个 
			while(top>0&&Stack[top-1]!=now){
				Q2[l2++]=Stack[top-1];
				book[Stack[top-1]]=0; 
				top--;
			}
			top--;
			Q2[l2++]=Stack[top];
		}else{
			Stack[top++]=now;
			book[now]=1;
		}
	}
	printf("%d",(l1==r1)?2:1); 
	return 0;
}
/*
Anything about this question:
From:
	queue stack
Description:
	扑克牌 过火车 
Example:
	1:
		Input:
			3
			1 2 3
			3 2 1
		Output:
			1
	2:
		Input:
			6
			2 4 1 2 5 6
			3 1 3 5 6 4
		Output:
			2
Type:
	例题 
Anything:
	空间换时间：标记数组 
*/
