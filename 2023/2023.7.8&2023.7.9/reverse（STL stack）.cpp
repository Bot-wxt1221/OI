#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);	getchar();
	while(n--) {
		stack<char> s;
		while(true) {
			char ch = getchar();
			if(ch ==' ' || ch == '\n' || ch == EOF) {
				while(!s.empty()) {
					printf("%c", s.top());	s.pop();
				}
				if(ch =='\n' || ch == EOF)	break;
				printf(" ");
			} else	s.push(ch);
		}
		printf("\n");
	}
	return 0;
}

