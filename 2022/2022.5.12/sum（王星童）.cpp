/*

*/
#include <iostream>
#include <cstdio>
#include <queue>
#define int long long
using namespace std;
deque<int>a;//�����ѡ��ǰ׺����С 
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
	Max=max(Max,Nowqian);//��һ������������ 
	for(int i=2;i<=n;i++){
		Nowqian+=b[i];//ά��ǰ׺�� 
		qian[i]=Nowqian;//���� 
		if(size<m){
			while(a.size()>0&&qian[a.back()]>=Nowqian){//ģ�� 
				a.pop_back();
			}
			size++;
			a.push_back(i);
			Max=max(Max,Nowqian-qian[a.front()]);//���� 
		}else{
			while(a.size()>0&&qian[a.back()]>=Nowqian){//ģ�� 
				a.pop_back();
			}
			size++;
			a.push_back(i);
			Max=max(Max,Nowqian-qian[a.front()]);//���� 
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
	ѵ���� 
Description:
	����һ������Ϊn���������У������ҳ�һ�β�����m�����������У�ʹ���������еĺ����
Example:
	1:
		In:
			6 4
			1 -3 5 1 -2 3
		Out:
			7
More:
	�ֽ����� 
How to AC:
	 ά�����кͿ��ǵ�ǰ׺�ͣ�һ�����еĺ�������ǰ׺�ͻ�ǰ׺�ͱ����ʾ��ʹ�õ�������ά������ѡ���ǰ׺���е���Сֵ 
*/


