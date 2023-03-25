#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

class node{
	public:
		char n[20];
		int t;
}aa; 
queue<node>a;
int main(){
	freopen("schedule.in","r",stdin);
	freopen("schedule.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%d",aa.n,&aa.t);
		a.push(aa);
	}
	int aaa=0;
	while(!a.empty()){
		node temp=a.front();
		a.pop();
		if(temp.t<=q){
			cout<<temp.n<<' '<<aaa+temp.t<<endl;
			aaa-=(q-temp.t);
		}else{
			temp.t-=q;
			a.push(temp);
		}
		aaa+=q;
	}
	return 0;
}
/*
Anything about this program:
Type:
	���� 
Description:
	�������� n �����̡�ÿ�����̶������ƣ� namei �� ����ʱ�䣺timei��CPU ͨ��ѭ�����Ȱ�˳��
������Щ���̡�ѭ�����ȳ���Ϊÿ�������ṩȷ����ʱ��Ƭ,����ý���δ��ʱ��Ƭ��ִ����ɣ���ô��
���̾ͻᱻ�жϡ�Ȼ��ý��̽����ָ����ƶ������е�ĩβ,Ȼ����ȳ����漴��ʼ��������е���һ��
���̡�
Example:
	1:
		In:
			5 100
			p1 150
			p2 80
			p3 200
			p4 350
			p5 20
		Out:
			p2 180
			p5 400
			p1 450
			p3 550
			p4 800
More:
	��Ҫ��ʱ��Ƭʱ���� 100 
*/

