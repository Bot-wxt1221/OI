#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
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
	freopen("St.in","w",stdout);
	int n=1000;
	srand(time(NULL));
	cout<<n<<endl;
	for(int i=1;i<=n;i++){
		cout<<rand()<<' ';
	}
	int m=1000;
	cout<<endl<<m<<endl;
	for(int i=1;i<=n;i++){
		int a=rand()%n+1,b=rand()%n+1;
		while(a>b){
			b=rand()%n+1;
		}
		cout<<a<<' '<<b<<endl;
	}
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



