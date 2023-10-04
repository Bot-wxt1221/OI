//��������ͼ���ڽӱ�
#include<iostream> 
using namespace std;
const int MaxVnum = 100; //���������ֵ
typedef char VexType; //�������������Ϊ�ַ���

typedef struct AdjNode { //�����ڽӵ�����
	int v; //�ڽӵ��±�
	struct AdjNode *next; //ָ����һ���ڽӵ�
} AdjNode;

typedef struct VexNode { //���嶥������
	VexType data; // VexTypeΪ������������ͣ�������Ҫ����
	AdjNode *first; //ָ���һ���ڽӵ�
} VexNode;

typedef struct {//�����ڽӱ�����
    VexNode Vex[MaxVnum];
    int vexnum,edgenum; //������������
} ALGraph;

int locatevex(ALGraph G,VexType x) {
    for(int i = 0; i < G.vexnum; i++)//���Ҷ�����Ϣ���±�
		if(x == G.Vex[i].data)
			return i;
    return -1;//û�ҵ�
}

void insertedge(ALGraph &G, int i, int j) {//����һ����
    AdjNode *s;
    s = new AdjNode;
    s->v = j;
    s->next = G.Vex[i].first;
    G.Vex[i].first = s;
}

void printg(ALGraph G) {//����ڽӱ�
	cout << "----------�ڽӱ����£�----------" << endl;
	for(int i = 0; i < G.vexnum; i++) {
		AdjNode *t = G.Vex[i].first;
		cout << G.Vex[i].data << "��  ";
		while(t!=NULL) {
			cout << "[" << t->v << "]\t";
			t = t->next;
		}
		cout<<endl;
	}
}

void CreateALGraph(ALGraph &G) {//��������ͼ�ڽӱ�
    int i, j;
    VexType u, v;
    cout << "�����붥�����ͱ���:" << endl;
    cin >> G.vexnum >> G.edgenum;
    cout << "�����붥����Ϣ:" << endl;
    for(i = 0; i < G.vexnum; i++)//���붥����Ϣ�����붥����Ϣ����
        cin >> G.Vex[i].data;
    for(i = 0; i < G.vexnum; i++)
        G.Vex[i].first = NULL;
    cout << "����������ÿ���ߵ���������u,v" << endl;
    while(G.edgenum--) {
        cin >> u >> v;
        i = locatevex(G, u);//���Ҷ���u�Ĵ洢�±�
        j = locatevex(G, v);//���Ҷ���v�Ĵ洢�±�
        if(i != -1 && j != -1)
			insertedge(G, i, j);
        else {
			cout << "���붥����Ϣ�����������룡" << endl;
			G.edgenum++; //�������벻��
        }
    }
}

int main(){
    ALGraph G;
    CreateALGraph(G);//��������ͼ�ڽӱ�
    printg(G);//����ڽӱ�
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
