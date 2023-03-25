#include <iostream>
using namespace std;

void EnQueue(int *Q, int x);              
int DeQueue(int *Q);
bool QueueEmpty(int *Q);

int Q[30] = {0};
int front, rear, Max_len;

int main(){
	int n, k, s, e;
	
	cin >> n;    
	for(int i = 1; i <= n; i++) { 
		 cout << " ";
	}   
	cout << '1' << endl;         // ������λ��������������˵�"1"
	front = rear = 1;  
	Max_len = n + 2;          // �����������Ϊ n+2 �Ŀն��� 
	
	EnQueue(Q, 0);           // ����н�ֵ 
	EnQueue(Q, 1);
	EnQueue(Q, 1);          // ��һ�е�ֵ����� 
	k = 1;
	while( k < n ){         // ͨ��ѭ���������ǰ n-1 �е�ֵ 
		for(int i = 1; i <= n - k; i++) {
			cout << " ";        // ���n-k���ո��Ա��������� 	
		}
		
		EnQueue(Q,0);        // �н�ֵ"0"����� 
		do{                   // ����� k �У������ k+1 �� 
		  s = DeQueue(Q);
		  e = Q[front];
		  if(e)	cout<< e << " ";    // ��eΪ���н�ֵ0�����ӡ��� e ��ֵ����һ�ո� 
		  else  cout << endl;       // ����س����У�Ϊ��һ�������׼��
		  EnQueue(Q, s + e);
		} while (e != 0);
		k++;
	}
	e = DeQueue(Q);              // �н�ֵ"0"������ 
	while(!QueueEmpty(Q)){                       // ��������� n �е�ֵ����� 
	  e = DeQueue(Q);
	  cout << e << " ";
	}
	
	return 0;
}


void EnQueue(int *Q,int x){     //���
	Q[rear] = x;
	if(rear == Max_len)  rear=1;
	else  rear++;
	return;
}
	
int DeQueue(int *Q){      //����
    int x;
	x = Q[front];
	if(front == Max_len) front = 1;
    else front++;
    return x;
}

bool QueueEmpty(int *Q){
	if((front == 1) && (rear == 1))  return false;
	else return true;    
}

