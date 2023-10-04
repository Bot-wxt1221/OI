#include <queue>
#include <iostream>
#include <cstdio>
#include <algorithm>
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
class node{
	public:
		int length,how;
};
bool operator<(node a,node b){
	return a.how<b.how;
}
bool cmp(node a,node b){
	return a.length<b.length;
}
priority_queue<node>a;
node b[10005];
int main(){
	freopen("expedition.in","r",stdin);
	freopen("expedition.out","w",stdout);
	int n;
	n=read();
	for(int i=1;i<=n;i++){
		b[i].length=read();
		b[i].how=read();
	}
	int l,p;
	l=read();p=read();
	for(int i=1;i<=n;i++){
		b[i].length=l-b[i].length;//�ӵ㣬�����ǵ�����ľ��룬�����Ǿ��������ľ��� 
	}
	int i1=1;
	int use=0;
	sort(b+1,b+n+1,cmp);//ȷ�������ԣ������������������� 
	while(p<l){
		use++;
		for(;i1<=n;i1++){
			if(b[i1].length<=p){//�ܹ��ߵ��ļ���վ 
				a.push(b[i1]);
			}else{
				break;
			}
		}
		if(a.size()>0){//����м���վ�Ǿͼ���֮�� 
			p+=a.top().how;
			a.pop();
		}else{
			cout<<-1;//û�м���վ�͵������� 
			return 0;
		}
	}
	cout<<use;
	return 0;
}
/*
Anything about this program:
Type:
	���� 
Description:
	һȺ��ţץ��һ��������ð�ս�����������̽�ա���Ϊ�൱����˾������ţ���ҵ��ܹ�һ����ʯ���̴��˿��������䡣��������ÿ��ʻһ
����λ�ľ���ͻ�й©һ����λ��ȼ�ϡ�
Ϊ������������ţ����Ҫ����һ���ֳ������·����������ĳ��򣨾��벻���� 1,000,000 ����λ����������·�ϣ��ڳ���Ϳ����ĵ�ǰλ��
֮�䣬�� N (1 <= N <= 10,000) ��ȼ��վ����ţ����ͣ������ȡ�����ȼ�ϣ�ÿ��վ 1..100 ����λ����
���ֶ�������˵��һ��Σ�յĵط�����ţ��˵����Σ�ա���ˣ���ţ��ϣ����ȥ�����·�Ͼ������ٵ�ͣ�������͡����˵��ǣ����ǿ����ϵ���
���������֮�����������������ɵ�ȼ����ʵ����û�����ơ�����Ŀǰ������� L ����λ�������� P ����λ��ȼ�� (1 <= P <= 1,000,000)��
ȷ������������������ͣ��������������ţ�Ƿ�����޷��������
Example:
	1:
		In:
			4
			4 4
			5 2
			11 5
			15 10
			25 10
		Out:
			2
Answer:
	̰�ģ�����·���ļ���վ�У����ĸ�����վ����վ���Ͳ�����Ҫ�����Ծ�ѡ��ǰ���ߵ��ļ���վ���ܼ������ļ���վ���м��ͣ����ͺ��ܵ���ļ���վ��һ�����࣬��Ҫ��̬ά��������������ʹ�����ȶ��н���ά��������ʹ�õ������У� 
*/

