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
		a=priority_queue<int>();//��� 
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
	���� 
Description:
	С����С��������һ���򵥵�������Ϸ��С����ÿ���п���ѡ��д��һ������������С����
k�������ʲô����ΪС��д������̫�࣬С�����ʵ�ͷ���ۻ������ڣ��������Ű���С����

Example:
	1:
		In:
			number2.in 
		Out:
			number2.out
ά��ǰk�����ĵ������� setЧ�ʽϵ� 
*/

