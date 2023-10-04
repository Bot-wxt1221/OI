#include<iostream>
#include<cstring>
using namespace std;
struct node{
	int a,b,w;
}e[210];
int dis[110];
int n,m,cnt=0;

void add(int a,int b,int w){
	e[cnt].a=a;
	e[cnt].b=b;
	e[cnt++].w=w;
}

bool bellman_ford(int u){//��Դ��u��������������·�����ȣ��и��� 
	memset(dis,0x3f,sizeof(dis));
	dis[u]=0;
	for(int i=1;i<n;i++){//ִ��n-1��
		bool flag=false;
		for(int j=0;j<m;j++)//����m��cnt
			if(dis[e[j].b]>dis[e[j].a]+e[j].w){
				dis[e[j].b]=dis[e[j].a]+e[j].w;
				flag=true;
			}
		if(!flag)
			return false;
	}
	for(int j=0;j<m;j++)//��ִ��1�Σ������ɳ�˵���л�
		if(dis[e[j].b]>dis[e[j].a]+e[j].w)
			return true;
	return false;
}

void print(){//���Դ�㵽�����ڵ����̾��� 
	cout<<"��̾��룺"<<endl; 
	for(int i=1;i<=n;i++)
		cout<<dis[i]<<" ";
	cout<<endl;
}

int main(){
	int a,b,w;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b>>w;
		add(a,b,w);
	}
	if(bellman_ford(1))//�жϸ���
		cout<<"�и�����"<<endl;
	else
		print();	
	return 0;
}
/*��������1 
5 8
1 2 2
1 3 5
2 3 2
2 4 6
3 4 7
3 5 1
4 3 2
4 5 4
*/
/*��������2���и��� 
4 4
1 2 3
2 3 -4
3 4 2
4 2 1
*/
