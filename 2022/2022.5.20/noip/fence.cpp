#include <iostream>
#include <cstdio>
#include <queue>
#define int unsigned long long
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
priority_queue<int>a;
signed main(){
//	freopen("fence.in","r",stdin);
//	freopen("fence.out","w",stdout);
	int n=read(),total=0,ans=0;
	for(int i=1;i<=n;i++){
		a.push(-read());//Ĭ�ϴ����ȡ�����Դ�С���� 
	}
	for(int i=1;i<=n-1;i++){
//		cout<<a1<<' '<<a2
		int a1=-a.top();
		a.pop();
		int a2=-a.top();
		a.pop();
		ans+=(a1+a2);
		a.push(-a1-a2);
	}
	cout<<ans;
	return 0;
}
/*
Anything about this program:
Type:
	���� 
Description:
	ũ��Լ����Ҫ�޸�������Χ��һС��Χ������������դ������������ҪN (1 �� N �� 20,000) ��ľ�壬ÿ��ľ�嶼��һ������������L 
i
 (1 �� L 
i
 ��
50,000) ����λ��Ȼ����������һ�鳤�壬�䳤�ȸպÿ��Ծ���N��ľ�壨�����䳤���ǳ���L 
i
���ܺͣ���FJ �����ˡ��пڡ���������ʱ���ĩ��
��ʧ�Ķ��ⳤ�ȣ���ҲӦ�ú�������
FJ �ź�����ʶ����û�о�ľͷ�ľ��ӣ�������������鳤���ߵ�ũ���Ƶ�ũ��������ò�������Ƿ���Խ�һ�Ѿ��ӡ�
�ڳ��ʱ��� Farmer Don û�н�� FJ һ�Ѿ��ӣ���������� Farmer John ��ȡN -1 ľ���ϵ�ÿһ���и�ķ��á��и�һ��ľͷ�ķ������õ�����
�ĳ��ȡ��и��Ϊ 21 ��ľ����Ҫ 21 ���֡�
Farmer Don Ȼ���� Farmer John �����и�ľ���˳���λ�á�����ũ��Լ��ȷ�������Ի��ѵ���ͽ��������N��ľ�塣FJ ֪���������Ը��ֲ�
ͬ��˳���и���ӣ��⽫���²�ͬ�ķ��ã���Ϊ���ɵ��м����в�ͬ�ĳ��ȡ�

Example:
	1:
		In:
			3 8 5 8
		Out:
			34
	2��
		In:
			5 4 8 2 3 6 
		Out:
			51
		Wrong Out:
			52
More:
���������������ֱ�Ϊ�ϲ� 

*/

