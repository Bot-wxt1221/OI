#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
char a[100];
int main(){
	srand(time(NULL));
	int have=-1;
	for(int i=0;i<26;i++){
		a[++have]=i+'a';
	}
	for(int i=0;i<26;i++){
		a[++have]=i+'A';
	}
	a[++have]='+';
	a[++have]='-';
	a[++have]='*';
	a[++have]='/';
	for(int i=0;i<10;i++){
		a[++have]=i+'0';
	}
	have++;
	freopen("word1.in","w",stdout);
	for(int i=1;i<=100;i++){
		cout<<a[rand()%(have)];
	}
	cout<<endl;
	for(int i=1;i<=100;i++){
		cout<<a[rand()%(have)];
	}
	return 0;
}

