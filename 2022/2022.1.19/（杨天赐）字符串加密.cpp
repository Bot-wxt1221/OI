#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;
string x;
int main(){
	while(getline(cin,x)){
		for(int i=0;i<x.length();++i){
			if('a'<=x[i]&&x[i]<='z') x[i]=(x[i]-'a'+1)%26+'a';
			if('A'<=x[i]&&x[i]<='Z') x[i]=(x[i]-'A'+1)%26+'A';
			putchar(x[i]);
		}
	}
	return 0;
}
