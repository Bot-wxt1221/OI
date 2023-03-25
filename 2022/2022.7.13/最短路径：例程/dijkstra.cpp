#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
const int MaxVnum=100; //城市的个数可修改
const int INF=0x3f3f3f3f; //无穷大
int dist[MaxVnum],p[MaxVnum];//最短距离和前驱数组
bool flag[MaxVnum]; //如果s[i]等于true，说明顶点i已经加入到集合S;否则顶点i属于集合V-S
typedef string VexType;  //顶点的数据类型，根据需要定义
typedef int EdgeType;  //边上权值的数据类型，若不带权值的图，则为0或1
typedef struct{
	VexType Vex[MaxVnum];
	EdgeType Edge[MaxVnum][MaxVnum];
	int vexnum,edgenum; //顶点数，边数
}AMGraph;

int locatevex(AMGraph G,VexType x){
    for(int i=0;i<G.vexnum;i++)//查找顶点信息的下标
		if(x==G.Vex[i])
        	return i;
    return -1;//没找到
}

void CreateAMGraph(AMGraph &G){
    int i,j,w;
    VexType u,v;
    cout<<"请输入顶点数："<<endl;
    cin>>G.vexnum;
    cout<<"请输入边数:"<<endl;
    cin>>G.edgenum;
    cout<<"请输入顶点信息:"<<endl;
    for(int i=0;i<G.vexnum;i++)//输入顶点信息，存入顶点信息数组
        cin>>G.Vex[i];
    for(int i=0;i<G.vexnum;i++)//初始化邻接矩阵为无穷大
		for(int j=0;j<G.vexnum;j++)
			G.Edge[i][j]=INF;
    cout<<"请输入每条边依附的两个顶点及权值："<<endl;
    while(G.edgenum--){
		cin>>u>>v>>w;
		i=locatevex(G,u);//查找顶点u的存储下标
		j=locatevex(G,v);//查找顶点v的存储下标
		if(i!=-1&&j!=-1)
			G.Edge[i][j]=w; //有向图邻接矩阵
		else{
			cout<<"输入顶点信息错！请重新输入！"<<endl;
			G.edgenum++;//本次输入不算
		}
    }
}

void Dijkstra(AMGraph G,int u){
	for(int i=0;i<G.vexnum;i++){
		dist[i]=G.Edge[u][i]; //初始化源点u到其他各个顶点的最短路径长度
		flag[i]=false;
		if(dist[i]==INF)
			p[i]=-1; //源点u到该顶点的路径长度为无穷大，说明顶点i与源点u不相邻
		else
			p[i]=u; //说明顶点i与源点u相邻，设置顶点i的前驱p[i]=u
	}
    dist[u]=0;
    flag[u]=true;   //初始时，集合S中只有一个元素：源点u
    for(int i=0;i<G.vexnum;i++){
        int temp=INF,t=u;
        for(int j=0;j<G.vexnum;j++) //在集合V-S中寻找距离源点u最近的顶点t
			if(!flag[j]&&dist[j]<temp){
            	t=j;
            	temp=dist[j];
        	}
        if(t==u) return; //找不到t，跳出循环
        flag[t]=true;  //否则，将t加入集合
        for(int j=0;j<G.vexnum;j++)//更新V-S中与t相邻接的顶点到源点u的距离
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
	cout<<"源点为："<<u<<endl;
	for(int i=0;i<G.vexnum;i++){
		x=p[i];
		if(x==-1&&u!=G.Vex[i]){
		    cout<<"源点到其它各顶点最短路径为："<<u<<"--"<<G.Vex[i]<<"    sorry,无路可达"<<endl;
		    continue;
		}
		while(x!=-1){
			S.push(x);
			x=p[x];
		}
		cout<<"源点到其它各顶点最短路径为：";
		while(!S.empty()){
			cout<<G.Vex[S.top()]<<"--";
			S.pop();
		}
		cout<<G.Vex[i]<<"    最短距离为："<<dist[i]<<endl;
	}
}

int main(){
    AMGraph G;
    int st;
    VexType u;
    CreateAMGraph(G);
    cout<<"请输入源点的信息:"<<endl;
    cin>>u;
    st=locatevex(G,u);//查找源点u的存储下标
    Dijkstra(G,st);
    cout<<"小明所在的位置:"<<u<<endl;
    for(int i=0;i<G.vexnum;i++){
        cout<<"小明:"<<u<<" - "<<"要去的位置:"<<G.Vex[i];
        if(dist[i]==INF)
			cout<<" sorry,无路可达"<<endl;
        else
			cout<<" 最短距离为:"<<dist[i]<<endl;
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
