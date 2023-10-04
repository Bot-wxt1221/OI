/*

*/
#include <iostream>
#include <cstdio>
#include <queue>
#define int long long
using namespace std;
deque<int>a;//求出待选的前缀和最小 
int b[300005];
int qian[300005];
signed main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&b[i]);
	}
	int Max=-0x7fffffff,nownum=0,Nowqian=0,size=0;
	Nowqian=b[1];
	size++;
	qian[1]=Nowqian;
	a.push_back(1);
	Max=max(Max,Nowqian);//第一个数进行特判 
	for(int i=2;i<=n;i++){
		Nowqian+=b[i];//维护前缀和 
		qian[i]=Nowqian;//保存 
		if(size<m){
			while(a.size()>0&&qian[a.back()]>=Nowqian){//模板 
				a.pop_back();
			}
			size++;
			a.push_back(i);
			Max=max(Max,Nowqian-qian[a.front()]);//更新 
		}else{
			while(a.size()>0&&qian[a.back()]>=Nowqian){//模板 
				a.pop_back();
			}
			size++;
			a.push_back(i);
			Max=max(Max,Nowqian-qian[a.front()]);//更新 
			if(a.front()==i-m){
				size--;
				a.pop_front();
			}
		}
	}
	cout<<Max;
	return 0;
}
/*
Anything about this program:
Type:
	训练题 
Description:
	输入一个长度为n的整数序列，从中找出一段不超过m的连续子序列，使得整个序列的和最大。
Example:
	1:
		In:
			6 4
			1 -3 5 1 -2 3
		Out:
			7
More:
	分解问题 
How to AC:
	 维护序列和考虑到前缀和，一个序列的和由两个前缀和或前缀和本身表示，使用单调队列维护可以选择的前缀和中的最小值 
*/


