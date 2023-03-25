#include <iostream>
#include <cstdio>
using namespace std;
char a[100],b[100];
int c[300];
int D,d,u; 
int main(){
	gets(a);gets(b);
	int size=-1;
	for(int i=0;a[i]!='\0';i++){
		c[a[i]]++;
	}
	for(int i=0;b[i]!='\0';i++){
		c[b[i]]++;
	}
	for(int i='a';i<='z';i++){
		if(c[i]){
			printf("出现了%c，出现了%d次\n",i,c[i]);
		}
	}
	for(int i='A';i<='Z';i++){
		if(c[i]){
			printf("出现了%c，出现了%d次\n",i,c[i]);
		}
	}
	return 0;
}
