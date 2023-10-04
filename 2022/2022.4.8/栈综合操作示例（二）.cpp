#include <iostream>
using namespace std;

const int N = 100;
//ʹ������ģ��ջ
int s[N+1]; 
int top = 0;
void push(int x);
void pop();
int getTop();
void clear();

int main(){
	push(15);
	cout << getTop() << endl;
	push(56);
	cout << getTop() << endl;
	push(78);
	pop(); clear();
	cout << getTop() << endl;
	return 0;
}

//1.��ջ��������ջ�ſ��Խ�����ջ����
void push(int x){
	if(top < N){
		top++;
		s[top] = x;
	} 
	return;
} 
 
//2.��ջ�����ǿ�ջ�ſ��Խ��г�ջ����
void pop(){
	if(top > 0){
		top--;
	}
	return;
} 

//3.��ȡջ��Ԫ��
int getTop(){
	return s[top];
} 

//4.���ջ
void clear(){
	top = 0;
	return;
} 
