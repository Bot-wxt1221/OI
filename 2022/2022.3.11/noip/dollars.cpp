/*
������һ�����һ��ģ�����ܹ���ֵ���ͻ� 
*/
#include <iostream>
#include <cstdio>
using namespace std;
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		c=='-'?f=-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f*x;
}
int a[105];
int main(){
	freopen("dollars.in","r",stdin);
	freopen("dollars.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	bool now=0;//0 ��Ԫ 1 ���
	double nowm=100; 
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1]&&now==0){
			now=1;
			nowm=nowm/100.0*a[i];
		}else if(a[i]<a[i+1]&&now==1){
			now=0;
			nowm=nowm/a[i]*100.0;
		}
	}
	if(now==1){
		nowm=nowm/a[n]*100.0;
	}
	printf("%.2lf",nowm);
	return 0;
}

