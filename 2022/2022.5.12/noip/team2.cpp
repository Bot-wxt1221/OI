#include <iostream>
#include <cstdio>
#include <queue> 
#include <cstring>
using namespace std;
int book[1000005];
bool go[1000005];
int main(){
	freopen("team.in","r",stdin);
	freopen("team.out","w",stdout);
	int t,n=1;
	scanf("%d",&t);
	char temp[10];
	while(t!=0){
		memset(go,0,sizeof(go));
		memset(book,0,sizeof(book));
		queue<int>b[1005];
		queue<queue<int> *>a;
		printf("Scenario #%d\n",n);
		for(int i=1;i<=t;i++){
			int m;
			scanf("%d",&m); 
			for(int j=1;j<=m;j++){
				int temp;
				scanf("%d",&temp);
				book[temp]=i;
			}
		}
		scanf("%s",temp);
		while(strcmp(temp,"STOP")!=0){
			if(strcmp(temp,"ENQUEUE")==0){
				int aa;
				scanf("%d",&aa);
				b[book[aa]].push(aa);
				if(go[book[aa]]==0){
					a.push(&(b[book[aa]]));
					go[book[aa]]=1;
				}
			}else{
				int temp=(*(a.front())).front();
//				cout<<(*(a.front())).front()<<endl;
				(*(a.front())).pop();
				if((*(a.front())).size()==0){
					go[book[temp]]=0;
					a.pop();
				} 
			}
			scanf("%s",temp);
		}
		n++;
		scanf("%d",&t);
//		printf("\n");
	} 
	return 0;
}
/*
Anything about this program:
Type:
	Example 
Description:
	���к����ȼ������Ǵ�����������ѧ�Ҷ�֪�������ݽṹ��Ȼ�����ŶӶ��в���Ϊ����֪�������������������ճ������С����磬�����ʱ�䣬���������ŶӶ��о����Ŷ�
���С�
���ŶӶ����У�ÿ��Ԫ�ض�����һ���Ŷӡ����һ��Ԫ�ؽ�����У������ȴ�ͷ��β�������У��������һЩ���ѣ�ͬһ���Ŷӵ�Ԫ�أ��Ƿ��Ѿ��ڶ����С�����ǣ����ͽ�
�����Ǻ���Ķ��С�������ǣ�����β��������в���Ϊ�µ����һ��Ԫ�أ��������ã������Ӿ�������ͨ������һ����Ԫ�ذ����������ŶӶ����г��ֵ�˳���ͷ��β����
����
��������Ǳ�дһ��ģ�������ŶӶ��еĳ���
���뽫����һ����������������ÿ���������������Ŷ����� t (1<=t<=1000) ��ʼ��Ȼ���� t ���Ŷ�������ÿ�����������ڸ��Ŷӵ�Ԫ��������Ԫ�ر�����ɡ�Ԫ���� 0 -
999999��Χ�ڵ�������һ���Ŷ������԰��� 1000 ��Ԫ�ء�
����������б��������ֲ�ͬ�����
ENQUEUE x - ��Ԫ�� x �����ŶӶ���
DEQUEUE - �����һ��Ԫ�ز�����Ӷ�����ɾ��
STOP - ������������
���� t�����뽫�� 0 ֵ��ֹ��
���棺һ�������������ܰ������ 200000����ʮ�����������ŶӶ��е�ʵ��Ӧ���Ǹ�Ч�ģ�һ��Ԫ�ص���Ӻͳ��Ӷ�Ӧ��ֻ���Ѻ㶨��ʱ�䡣
Example:
	1:
		In:
			team.in/team2.in/team4.in
		Out:
			team.out/team2.out/team4.out
More:
	1 ��ģ�ͣ���һ��Ҫ����ά���������У���Ϊ�漰ʵ��˫�˶��еĲ��룬Ҫ�ҵ�����λ��ʱ�临�ӶȲ��ɽ���
	2 ע��ϸ�ڣ���˭��sizeof(book)д��sizeof(0) ��0 
	3 �������ٱ�����飺�������ì�ܵ����ڴ����
	�ϰ汾���ڴ�δ���Ż� 
*/

