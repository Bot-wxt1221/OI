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
	cout << '1' << endl;         // 在中心位置输出杨辉三角最顶端的"1"
	front = rear = 1;  
	Max_len = n + 2;          // 设置最大容量为 n+2 的空队列 
	
	EnQueue(Q, 0);           // 添加行界值 
	EnQueue(Q, 1);
	EnQueue(Q, 1);          // 第一行的值入队列 
	k = 1;
	while( k < n ){         // 通过循环队列输出前 n-1 行的值 
		for(int i = 1; i <= n - k; i++) {
			cout << " ";        // 输出n-k个空格以保持三角型 	
		}
		
		EnQueue(Q,0);        // 行界值"0"入队列 
		do{                   // 输出第 k 行，计算第 k+1 行 
		  s = DeQueue(Q);
		  e = Q[front];
		  if(e)	cout<< e << " ";    // 若e为非行界值0，则打印输出 e 的值并加一空格 
		  else  cout << endl;       // 否则回车换行，为下一行输出做准备
		  EnQueue(Q, s + e);
		} while (e != 0);
		k++;
	}
	e = DeQueue(Q);              // 行界值"0"出队列 
	while(!QueueEmpty(Q)){                       // 单独处理第 n 行的值的输出 
	  e = DeQueue(Q);
	  cout << e << " ";
	}
	
	return 0;
}


void EnQueue(int *Q,int x){     //入队
	Q[rear] = x;
	if(rear == Max_len)  rear=1;
	else  rear++;
	return;
}
	
int DeQueue(int *Q){      //出队
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

