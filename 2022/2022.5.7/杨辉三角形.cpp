#include <iostream>
#include <cstdio>
#define Max 1005
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
int Q[Max];
int r=0,l=0,num=0; 
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int n=read();
	Q[l]=1;
	cout<<1<<endl;
	l=(l+1)%Max;
	for(int i=2;i<=n;i++){
		cout<<1<<' ';
		Q[l]=1;
		l=(l+1)%Max;
		for(int j=1;j<=i-2;j++){
			cout<<Q[r]+Q[r+1]<<' ';
			Q[l]=Q[r]+Q[r+1];
			r=(r+1)%Max;
			l=(l+1)%Max;
		}
		r=(r+1)%Max;
		Q[l]=1;
		l=(l+1)%Max;
		cout<<1<<' '<<endl;
	} 
	return 0;
}
/*
Anything about this question:
From:
	queue 
Description:
	打印杨辉三角形 
Example:
	1:
		Input:
			10
		OutPut:
			1
			1 1
			1 2 1
			1 3 3 1
			1 4 6 4 1
			1 5 10 10 5 1
			1 6 15 20 15 6 1
			1 7 21 35 35 21 7 1
			1 8 28 56 70 56 28 8 1
			1 9 36 84 126 126 84 36 9 1
Type:
	例题 
*/

