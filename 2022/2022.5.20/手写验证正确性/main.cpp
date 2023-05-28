#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int read(){
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
		int a=clock();
		system("1.exe");
		cout<<clock()-a<<"ms"<<endl;
		a=clock();
		system("2.exe");
		cout<<clock()-a<<"ms"<<endl;
	}while(!system("fc 1.out 2.out"));
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

