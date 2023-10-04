#include <iostream>
using namespace std;

const int N = 100;
//使用数组模拟栈
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

//1.入栈：不是满栈才可以进行入栈操作
void push(int x){
	if(top < N){
		top++;
		s[top] = x;
	} 
	return;
} 
 
//2.出栈：不是空栈才可以进行出栈操作
void pop(){
	if(top > 0){
		top--;
	}
	return;
} 

//3.获取栈顶元素
int getTop(){
	return s[top];
} 

//4.清空栈
void clear(){
	top = 0;
	return;
} 
