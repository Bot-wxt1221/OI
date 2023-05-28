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
bool map[5000][5000];
int main(){
//	freopen(".in","r",stdin);
	freopen("h.in","w",stdout);
	int n=500,m=rand()%249500+500;
	srand(time(NULL));
	cout<<n<<' '<<m<<' '<<rand()%500+1<<endl;
	for(int i=1;i<=m;i++){
		int a=0,b=0;
		do{
			a=rand()%500+1;
			b=rand()%500+1;
		}
		while(a==b&&map[a][b]==0);
		map[a][b]=1;
		cout<<a<<' '<<b<<' '<<rand()%10<<endl;
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



