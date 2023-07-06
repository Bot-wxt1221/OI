//���P1540, ��дѭ������ 
#include <bits/stdc++.h>
const int N = 1003;               //���д�С

int Hash[N] = {0};            //��Hash����ڴ�����û�е��� 

struct myqueue { 
	int data[N];             //���侲̬�ռ� 
	/* �����̬���䣬����д�� int *data;    */
	int head, rear;          //��ͷ����β
	bool init() {            //��ʼ��
		/*�����̬���䣬����д��
		Q.data = (int *)malloc(N * sizeof(int)) ;
		if(!Q.data) return false;        */
		head = rear = 0;
		return true;
	}
	int size() {
		return (rear - head + N) % N;   //���ض��г��� 
	}
	bool empty() {              //�ж϶����Ƿ�Ϊ�� 
		if(size()==0) return true;
		else          return false;
	}
	bool push(int e) {          //��β������Ԫ�ء��µ�rearָ����һ���յ�λ�� 
		if((rear + 1) % N == head ) return false;    //������ 
		data[rear] = e;
		rear = (rear + 1) % N;
		return true;
	}
	bool pop(int &e) {          //ɾ����ͷԪ�أ��������� 
		if(head == rear) return false;       //���п� 
		e = data[head];
		head = (head + 1) % N;
		return true;
	}
	int front() {
		return data[head];    //���ض��ף����ǲ�ɾ��
	}
} Q;

int main() {
	Q.init();                    //��ʼ������
	int m, n;
	scanf("%d%d", &m, &n);
	int cnt = 0;
	while(n--) {
		int en;
		scanf("%d",&en);    //����һ��Ӣ�ĵ���
		if(!Hash[en]) {              //����ڴ���û���������
			++cnt;
			Q.push(en);              //���ʽ����У��ŵ�����β��
			Hash[en] = 1;
			while(Q.size() > m) {      //�ڴ�����
				int tmp;
				Q.pop(tmp);     //ɾ����ͷ
				Hash[tmp] = 0;       //���ڴ���ȥ������
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}

