#include <iostream>
#include <cstdio>
#include <queue>
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
bool have[1005];
queue<int>a;
int main(){
	freopen("machine.in","r",stdin);
	freopen("machine.out","w",stdout);
	int m,n;
	m=read();
	n=read();
	int find=0;
	for(int i=1;i<=n;i++){
		int temp=read();
		if(have[temp]){//�л��� 
			continue;
		}else if(a.size()==m){//û��������ڴ����� 
			have[a.front()]=0;
			a.pop();//���� 
			a.push(temp);//���� 
			have[temp]=1;
		}else{//û���浫�ڴ�û�� 
			a.push(temp);
			have[temp]=1;
		}
		find++;
	}
	cout<<find;
	return 0;
}
/*
Anything about this program:
Type:
	���� 
Description:
	������������ԭ��ܼ򵥣���ֻ�Ǵ�ͷ��β�����ν�ÿ��Ӣ�ĵ����ö�Ӧ�����ĺ������滻����
��ÿ��Ӣ�ĵ��ʣ�����������ڴ��в���������ʵ����ĺ��壬����ڴ����У�����ͻ���������
���룻����ڴ���û�У�����ͻ�������еĴʵ��ڲ��ң�������ʵ����ĺ���Ȼ���룬������
�����ʺ���������ڴ棬�Ա������Ĳ��Һͷ��롣
�����ڴ����� ����Ԫ��ÿ��Ԫ�ܴ��һ�����ʺ����塣ÿ�������һ���µ��ʴ����ڴ�ǰ�����
��ǰ�ڴ����Ѵ���ĵ����������� ������Ὣ�µ��ʴ���һ��δʹ�õ��ڴ浥Ԫ�����ڴ���
�Ѵ��� �����ʣ�����������������ڴ���Ǹ����ʣ��ڳ���Ԫ��������µ��ʡ�
����һƪӢ�����µĳ���Ϊ �����ʡ�������ƪ�������£����������Ҫȥ�����Ҷ��ٴδʵ䣿
�����ڷ��뿪ʼǰ���ڴ���û���κε��ʡ�
Example:
	1:
		In:
		3 7
		1 2 1 5 4 4 1
		Out:
		5
More:
	һ�ι� 
*/

