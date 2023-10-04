#include <iostream>
using namespace std;
int k = 0, n;
void mov(int n, char a, char c, char b);   //用b柱作为协助过渡，将a柱上的（n）移到c柱上

int main() {
	cout << "n=";
	cin >> n;
	mov(n, 'a', 'c', 'b'); 
	
	return 0;
}
void mov(int n, char a, char c, char b) {  //用b柱作为协助过渡，将a柱上的（n）移到c柱上
	if (n == 0) return;            //如果n=0，则退出，即结束程序
	mov(n - 1, a, b, c);            //用c柱作为协助过渡，将a柱上的（n-1）片移到b柱上
	k++;
	cout << k << " :from " << a << "-->" << c << endl;
	mov(n - 1, b, c, a);             //用a柱作为协助过渡，将b柱上的（n-1）移到c柱上
	
	return;
}
