//��������ͼ���ڽӾ���
#include<iostream>
#define MaxVnum 100  //���������ֵ
using namespace std;

typedef char VexType;  //������������ͣ�������Ҫ����
typedef int EdgeType;  //����Ȩֵ���������ͣ�������Ȩֵ��ͼ����Ϊ0��1
typedef struct {
	VexType Vex[MaxVnum];
	EdgeType Edge[MaxVnum][MaxVnum];
	int vexnum, edgenum; //������������
} AMGraph;

int locatevex(AMGraph G, VexType x) {
    for(int i = 0; i < G.vexnum; i++) //���Ҷ�����Ϣ���±�
		if(x == G.Vex[i])
			return i;
    return -1; //û�ҵ�
}


void CreateAMGraph(AMGraph &G) {   
    VexType u, v;
    cout << "�����붥������" << endl;
    cin >> G.vexnum;
    cout << "���������:" << endl;
    cin >> G.edgenum;
    cout << "�����붥����Ϣ:" << endl;
    for(int i = 0; i < G.vexnum; i++)//���붥����Ϣ�����붥����Ϣ����
        cin >> G.Vex[i];
    for(int i = 0; i < G.vexnum; i++)//��ʼ���ڽӾ�������ֵΪ 0��������������ʼ���ڽӾ���Ϊ�����
		for(int j = 0; j < G.vexnum; j++)
			G.Edge[i][j ]= 0;
    cout << "������ÿ�����������������㣺" << endl;
    int i, j;
    while(G.edgenum--) {
		cin >> u >> v;
		i = locatevex(G, u);//���Ҷ���u�Ĵ洢�±�
		j = locatevex(G, v);//���Ҷ���v�Ĵ洢�±�
		if(i != -1 && j != -1)
			G.Edge[i][j] = G.Edge[j][i] = 1; //�ڽӾ�����1
		else {
			cout << "���붥����Ϣ�����������룡" << endl;
			G.edgenum++;//�������벻��
		}
    }
}

void print(AMGraph G) {//����ڽӾ���
    cout << "ͼ���ڽӾ���Ϊ��" << endl;
    for(int i = 0; i < G.vexnum; i++) {
        for(int j = 0; j < G.vexnum; j++)
			cout << G.Edge[i][j] << "\t";
        cout << endl;
    }
}

int main(){
	AMGraph G;
    CreateAMGraph(G);
    print(G);
    return 0;
}
/*
4 5
a b c d
a b
a d
b c
b d
c d
*/

