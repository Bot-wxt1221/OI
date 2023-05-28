#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <windows.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		c=='-'?f=-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f*x;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	do{
		system("data.exe");
		unsigned long t=GetTickCount();
		system("disij....exe");
		printf("%u\n",GetTickCount()-t);
		t=GetTickCount();
		system("spfa.exe");
		printf("%u\n",GetTickCount()-t);
	}while(!system("fc 1.out 4.out"));
	return 0;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/



