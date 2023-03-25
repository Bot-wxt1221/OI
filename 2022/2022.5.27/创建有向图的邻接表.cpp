//创建有向图的邻接表
#include<iostream> 
using namespace std;
const int MaxVnum = 100; //顶点数最大值
typedef char VexType; //顶点的数据类型为字符型

typedef struct AdjNode { //定义邻接点类型
	int v; //邻接点下标
	struct AdjNode *next; //指向下一个邻接点
} AdjNode;

typedef struct VexNode { //定义顶点类型
	VexType data; // VexType为顶点的数据类型，根据需要定义
	AdjNode *first; //指向第一个邻接点
} VexNode;

typedef struct {//定义邻接表类型
    VexNode Vex[MaxVnum];
    int vexnum,edgenum; //顶点数，边数
} ALGraph;

int locatevex(ALGraph G,VexType x) {
    for(int i = 0; i < G.vexnum; i++)//查找顶点信息的下标
		if(x == G.Vex[i].data)
			return i;
    return -1;//没找到
}

void insertedge(ALGraph &G, int i, int j) {//插入一条边
    AdjNode *s;
    s = new AdjNode;
    s->v = j;
    s->next = G.Vex[i].first;
    G.Vex[i].first = s;
}

void printg(ALGraph G) {//输出邻接表
	cout << "----------邻接表如下：----------" << endl;
	for(int i = 0; i < G.vexnum; i++) {
		AdjNode *t = G.Vex[i].first;
		cout << G.Vex[i].data << "：  ";
		while(t!=NULL) {
			cout << "[" << t->v << "]\t";
			t = t->next;
		}
		cout<<endl;
	}
}

void CreateALGraph(ALGraph &G) {//创建有向图邻接表
    int i, j;
    VexType u, v;
    cout << "请输入顶点数和边数:" << endl;
    cin >> G.vexnum >> G.edgenum;
    cout << "请输入顶点信息:" << endl;
    for(i = 0; i < G.vexnum; i++)//输入顶点信息，存入顶点信息数组
        cin >> G.Vex[i].data;
    for(i = 0; i < G.vexnum; i++)
        G.Vex[i].first = NULL;
    cout << "请依次输入每条边的两个顶点u,v" << endl;
    while(G.edgenum--) {
        cin >> u >> v;
        i = locatevex(G, u);//查找顶点u的存储下标
        j = locatevex(G, v);//查找顶点v的存储下标
        if(i != -1 && j != -1)
			insertedge(G, i, j);
        else {
			cout << "输入顶点信息错！请重新输入！" << endl;
			G.edgenum++; //本次输入不算
        }
    }
}

int main(){
    ALGraph G;
    CreateALGraph(G);//创建有向图邻接表
    printg(G);//输出邻接表
    return 0;
}
/*
5 7
a b c d e
a b
a c
a e
b c
c d
c e
d e
*/
