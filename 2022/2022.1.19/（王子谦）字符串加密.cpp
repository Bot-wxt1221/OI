#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main () {
	char a [ 1001 ];//定义输入的字符串 
	while ( cin.getline ( a, 1001 ) ) {//进行不断输入 
		int i = 0;
		while ( a [ i ] != '\0' ) {//当整个字符串读完后结束处理循环 
			if ( a [ i ] == ' ' ) {//当a [ i ]为空格时直接输出 
				cout << a [ i ];
				i ++;
			}else{//否则进行处理 
				a [ i ] ++;
				cout << a [ i ];
				i ++;
			}
		}
		cout << endl;
	}
	return 0;
}
