#include <cstdio>
#include <iostream>
void printfbin(char c);
using namespace std;
int main() {
	char a;
	cin>>a;
	printfbin(a);
	return 0;
}
void printfbin(char c){
	int t;
	for(int i=7;i>=0;i--){
		t=c>>i;
		t=t&1;
		printf("%d",t);
	}
	putchar('\n');
}
