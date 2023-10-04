#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
const int MaxVnum=100; //���еĸ������޸�
const int INF=0x3f3f3f3f; //�����
int dist[MaxVnum],p[MaxVnum];//��̾����ǰ������
bool flag[MaxVnum]; //���s[i]����true��˵������i�Ѿ����뵽����S;���򶥵�i���ڼ���V-S
typedef string VexType;  //������������ͣ�������Ҫ����
typedef int EdgeType;  //����Ȩֵ���������ͣ�������Ȩֵ��ͼ����Ϊ0��1
typedef struct{
	VexType Vex[MaxVnum];
	EdgeType Edge[MaxVnum][MaxVnum];
	int vexnum,edgenum; //������������
}AMGraph;

int locatevex(AMGraph G,VexType x){
    for(int i=0;i<G.vexnum;i++)//���Ҷ�����Ϣ���±�
		if(x==G.Vex[i])
        	return i;
    return -1;//û�ҵ�
}

void CreateAMGraph(AMGraph &G){
    int i,j,w;
    VexType u,v;
    cout<<"�����붥������"<<endl;
    cin>>G.vexnum;
    cout<<"���������:"<<endl;
    cin>>G.edgenum;
    cout<<"�����붥����Ϣ:"<<endl;
    for(int i=0;i<G.vexnum;i++)//���붥����Ϣ�����붥����Ϣ����
        cin>>G.Vex[i];
    for(int i=0;i<G.vexnum;i++)//��ʼ���ڽӾ���Ϊ�����
		for(int j=0;j<G.vexnum;j++)
			G.Edge[i][j]=INF;
    cout<<"������ÿ�����������������㼰Ȩֵ��"<<endl;
    while(G.edgenum--){
		cin>>u>>v>>w;
		i=locatevex(G,u);//���Ҷ���u�Ĵ洢�±�
		j=locatevex(G,v);//���Ҷ���v�Ĵ洢�±�
		if(i!=-1&&j!=-1)
			G.Edge[i][j]=w; //����ͼ�ڽӾ���
		else{
			cout<<"���붥����Ϣ�����������룡"<<endl;
			G.edgenum++;//�������벻��
		}
    }
}

void Dijkstra(AMGraph G,int u){
	for(int i=0;i<G.vexnum;i++){
		dist[i]=G.Edge[u][i]; //��ʼ��Դ��u������������������·������
		flag[i]=false;
		if(dist[i]==INF)
			p[i]=-1; //Դ��u���ö����·������Ϊ�����˵������i��Դ��u������
		else
			p[i]=u; //˵������i��Դ��u���ڣ����ö���i��ǰ��p[i]=u
	}
    dist[u]=0;
    flag[u]=true;   //��ʼʱ������S��ֻ��һ��Ԫ�أ�Դ��u
    for(int i=0;i<G.vexnum;i++){
        int temp=INF,t=u;
        for(int j=0;j<G.vexnum;j++) //�ڼ���V-S��Ѱ�Ҿ���Դ��u����Ķ���t
			if(!flag[j]&&dist[j]<temp){
            	t=j;
            	temp=dist[j];
        	}
        if(t==u) return; //�Ҳ���t������ѭ��
        flag[t]=true;  //���򣬽�t���뼯��
        for(int j=0;j<G.vexnum;j++)//����V-S����t���ڽӵĶ��㵽Դ��u�ľ���
			if(!flag[j]&&G.Edge[t][j]<INF)
				if(dist[j]>(dist[t]+G.Edge[t][j])){
					dist[j]=dist[t]+G.Edge[t][j];
					p[j]=t;
            	}
    }
}

void findpath(AMGraph G,VexType u){
	int x;
	stack<int>S;
	cout<<"Դ��Ϊ��"<<u<<endl;
	for(int i=0;i<G.vexnum;i++){
		x=p[i];
		if(x==-1&&u!=G.Vex[i]){
		    cout<<"Դ�㵽�������������·��Ϊ��"<<u<<"--"<<G.Vex[i]<<"    sorry,��·�ɴ�"<<endl;
		    continue;
		}
		while(x!=-1){
			S.push(x);
			x=p[x];
		}
		cout<<"Դ�㵽�������������·��Ϊ��";
		while(!S.empty()){
			cout<<G.Vex[S.top()]<<"--";
			S.pop();
		}
		cout<<G.Vex[i]<<"    ��̾���Ϊ��"<<dist[i]<<endl;
	}
}

int main(){
    AMGraph G;
    int st;
    VexType u;
    CreateAMGraph(G);
    cout<<"������Դ�����Ϣ:"<<endl;
    cin>>u;
    st=locatevex(G,u);//����Դ��u�Ĵ洢�±�
    Dijkstra(G,st);
    cout<<"С�����ڵ�λ��:"<<u<<endl;
    for(int i=0;i<G.vexnum;i++){
        cout<<"С��:"<<u<<" - "<<"Ҫȥ��λ��:"<<G.Vex[i];
        if(dist[i]==INF)
			cout<<" sorry,��·�ɴ�"<<endl;
        else
			cout<<" ��̾���Ϊ:"<<dist[i]<<endl;
    }
    findpath(G,u);
    return 0;
}
/*
5 8
1 2 3 4 5
1 2 2
1 3 5
2 3 2
2 4 6
3 4 7
3 5 1
4 3 2
4 5 4
1
*/
