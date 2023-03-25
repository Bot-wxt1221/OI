#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
int read(){
	int a=0,x=1;
	char temp=getchar();
	while('0'>temp||temp>'9'){
		(temp=='-')?(x=-1):1;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		a=(a<<3)+(a<<1)+(temp^'0');
		temp=getchar();
	}
	return a*x;
}
int n;
char a[10000005];
int c[10000005];
int l[10000006],r[10000005];
int op[10000006];
int now=100000;
int xa[10000005];
int x[10000005];
stack<int>sta;
int build(){
	int in=0;
	int temp1;
	do{
		in++;
	scanf("%s",a);
	if(a[0]=='!'){
		xa[temp1]^=1;
	}else if(a[0]=='x'){
//		int temp;
		char temp2;
 		sscanf(a,"%c%d",&temp2,&temp1);
		sta.push(temp1);
//		return temp;
	}else if(a[0]=='|'){
		now++;
		op[now]='|';
		l[now]=sta.top();
		sta.pop();
		r[now]=sta.top();
		sta.pop();
		temp1=now;
		sta.push(now);
	}else if(a[0]=='&'){
		now++;
		op[now]='&';
		l[now]=sta.top();
		sta.pop();
		r[now]=sta.top();
		sta.pop();
		temp1=now;
		sta.push(now);
	}else{
		sscanf(a,"%d",&n);
		break;
	}
	}while(1) ;
	return now;
}
bool ans[100005];
int build2(int now){
	if(now<=100000){
		return x[now]^xa[now];
	}
	int a=build2(l[now]);
	int b=build2(r[now]);
	if(op[now]=='|'){
		if(a==1)	c[r[now]]=1;
		if(b==1)	c[l[now]]=1;
		return (a|b)^(xa[now]);
	}else{
		if(a==0)	c[r[now]]=1;
		if(b==0)	c[l[now]]=1;
		return (a&b)^(xa[now]);
	}
}
void build3(int now){
	if(now<=100000){
		return ;
	}
	c[l[now]]|=c[now];
	c[r[now]]|=c[now];
	build3(l[now]);
	build3(r[now]);
	return ;
}
int main(){
	int begin=build();
//	n=read();
	for(int i=1;i<=n;i++){
		x[i]=read();
	}
	int ans=build2(begin);
	build3(begin);
	int q=read();
	for(int i=1;i<=q;i++){
		int a=read();
		printf("%d\n",!(ans^c[a]));
	}
	return 0;
}