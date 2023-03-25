#include <cstdio>
#include <iostream>
using namespace std;

int a[1005], now;

int main(){
	a[1] = 1;
	int c = 1;
	while (++c){
		for(int i = c; i >= 1; i--){
			a[i] = (a[i - 1] ^ a[i]);
			if (a[i] == 0) now++;
			if (now == 2014) break;
		}
		for(int i = 1; i <= c; i++) cout << a[i] << " ";cout<<endl;
		if(now == 2014) break;
	}
	cout << c;
	
}
