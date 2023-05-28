#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 4;
int mg[MAX][MAX] = {
	{0, 1, 0, 0},
 	{0, 0, 1, 1},
 	{0, 1, 0, 0},
 	{0, 0, 0, 0}
};
int m = 4, n = 4;
int dx[] = {-1, 0, 1, 0};   	//x�����ƫ����
int dy[] = {0, 1, 0, -1};   	//y�����ƫ����
struct Box{				//��������
	int i;				//������к�
   	int j;				//������к�
   	int di;				//di����һ�����ڿ��߷�λ�ķ�λ��
   	Box() {}				//���캯��
   	Box(int i1,int j1,int d1):
		i(i1),j(j1),di(d1) {}  		//���ع��캯��
};

bool mgpath(int xi, int yi, int xe, int ye);
void disppath(stack<Box> &st);

int main(){  
	int xi = 0, yi = 0, xe = 3, ye = 3;
   	printf("��(%d,%d)��(%d,%d)���Թ�·��\n", xi, yi, xe, ye);
   	if (!mgpath(xi, yi, xe, ye))
    	cout << "�������Թ�·��\n";
   	return 0;
}

bool mgpath(int xi, int yi, int xe, int ye){	//��һ����(xi,yi)��(xe,ye)���Թ�·��
	int i, j, di, i1, j1;
   	bool find;
   	Box b, b1;
   	stack<Box> st;			//����һ��ջ
   	b = Box(xi, yi, -1);
   	st.push(b);				//��ڷ����ջ
   	mg[xi][yi] = -1;			//Ϊ�������������ڷ�����mgֵΪ-1
	while (!st.empty()){			//ջ����ʱѭ�
		b = st.top();			//ȡջ������,��Ϊ��ǰ����
    	if (b.i == xe && b.j == ye){		//������,���ջ�����з��鹹��һ��·��
			disppath(st);
         	return true;			//�ҵ�һ��·���󷵻�true
      	}
		find = false;				//���������·��
     	di = b.di;
    	while (di < 3 && find == false){		//��b��һ�����ڿ��߷���
    		di++;				//����һ����λ�����ڷ���
        	i = b.i + dx[di];			//��b��di��λ�����ڷ���(i,j)
        	j = b.j + dy[di];
        	if (i >= 0 && i < m && j >= 0 && j < n && mg[i][j] == 0)
            find = true;			//(i,j)������Ч�ҿ���
     	}
     	if (find){				//�ҵ�һ�����ڿ��߷���(i,j)
			st.top().di = di;			//�޸�ջ�������diΪ��ֵ
        	b1 = Box(i, j, -1);			//�������ڿ��߷���(i,j)�Ķ���b1
        	st.push(b1);			//b1��ջ 
        	mg[i][j] = -1;			//Ϊ�������������ڷ�����mgֵΪ-1
     	}
     	else{				//ջ������û���ҵ��κ����ڿ��߷���
			mg[b.i][b.j] = 0;			//�ָ�ջ��������Թ�ֵ
        	st.pop();			//��ջ��������ջ
     	}
   }
   	return false;				//û���ҵ��Թ�·��,����false
}

void disppath(stack<Box> &st){		//���ջ�����з��鹹��һ���Թ�·��
	Box b;
   	vector<Box> apath;			//���һ���Թ�·��
   	while (!st.empty()){			//��ջ���еķ���
		b = st.top(); st.pop();
      	apath.push_back(b);
   	}
   	reverse(apath.begin(),	apath.end());	//����apath(Ҳ����ֱ�ӷ������apath)
   	cout << "һ���Թ�·��: ";
   	for (int i = 0; i < apath.size(); i++)
      cout << "[" << apath[i].i << "," << apath[i].j << "]  "; 
   cout << endl;
}


