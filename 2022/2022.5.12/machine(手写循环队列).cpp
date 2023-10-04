#include <cstdio>
#include <iostream>
using namespace std;

const int MAXQSIZE = 1003; //���д�С
int book[MAXQSIZE] = {0}; //�� book ����ڴ�����û�е���
struct myqueue {
	int data[MAXQSIZE]; //���侲̬�ռ�
	/* �����̬���䣬������д�� int *data; */
	int front; //��ͷ��ָ���ͷ��Ԫ��
	int rear; //��β��ָ����һ�����Է�Ԫ�صĿ�λ��
	bool init(){ //��ʼ��
		/*�����̬���䣬������д��
		Q.data = (int *)malloc(MAXQSIZE * sizeof(int)) ;
		if(!Q.data) return false; */
		front = rear = 0;
		return true;
	}
	int size() { //���ض��г���
		return (rear - front + MAXQSIZE) % MAXQSIZE;
	}
	bool push(int e) { //��β������Ԫ�ء��µ�rear ָ����һ���յ�λ��
		if((rear + 1) % MAXQSIZE == front ) return false; //������
		data[rear] = e;
		rear = (rear + 1) % MAXQSIZE;
		return true;
	}
	bool pop(int &e) { //ɾ����ͷԪ�أ���������
		if(front == rear) return false; //���п�
		e = data[front];
		front = (front + 1) % MAXQSIZE;
		return true;
	}
} Q;

int main(){
	freopen("machine.in", "r", stdin);
	freopen("machine.out", "w", stdout);
	Q.init(); //��ʼ������
	int m,n; scanf("%d%d",&m,&n);
	int cnt = 0;
	while(n--) {
		int en; scanf("%d",&en); //����һ��Ӣ�ĵ���
		if(!book[en]) { //����ڴ���û���������
			++cnt;
			Q.push(en); //���ʽ����У��ŵ�����β��
			book[en]=1;
			while(Q.size()>m) { //�ڴ�����
				int tmp;
				Q.pop(tmp); //ɾ����ͷ
				book[tmp] = 0; //���ڴ���ȥ������
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}

/*
����:
3 7
1 2 1 5 4 4 1

���:
5
*/
