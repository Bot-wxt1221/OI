#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int read(){
	char a=getchar();
	int f=1,x=0;
	while('0'>a||a>'9'){
		(a=='-')?f=-1:0;
		a=getchar();
	}
	while('0'<=a&&a<='9'){
		x=(x<<3)+(x<<1)+(a-'0');
		a=getchar();
	}
	return f*x;
}
char p[20];
void out(register int a){
	int i=0;
	while(a>0){
		p[++i]=a%10+'0';
		a/=10;
	}
	while(i--){
		putchar(p[i+1]);
	}
	return ;
}
priority_queue<int>a;
int main(){
	freopen("earthworm.in","r",stdin);
	freopen("earthworm.out","w",stdout);
	register int n=read(),m,q,u,v,t;
	m=read();
	q=read();
	u=read();
	v=read();
	t=read();
	for(register int i=1;i<=n;i++){
		a.push(read());
	}
	for(register int i=1;i<=m;i++){
		register int temp=a.top()+(i-1)*q;
		if(i%t==0){
			out(temp);
			putchar(' ');
		}
		a.pop();
		int a1=temp*u/v;
		int b1=temp-a1;
		a.push(a1-q*(i));
		a.push(b1-q*(i));
	}
	putchar('\n');
	for(register int i=1;i<=n+m;i++){
		register int temp=a.top();
		if(i%t==0){
			out(temp+q*m);
			putchar(' ');
		}
		a.pop();
	}
	putchar('\n');
	return 0;
}

