#include <iostream>
#include <cstdio>
#include <queue>
int read(){
	int x=0,op=1;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		op=((temp=='-')?-1:1);
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return x*op;
}
std::priority_queue<int>qu;
int fir[1005];
int nxt[1005];
int v[1005];
int in[1005];
int now;
void add(int x,int y){
	now++;
	v[now]=y;
	nxt[now]=fir[x];
	fir[x]=now;
	in[y]++;
	return ;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("correct.in","r",stdin);
	freopen("correct.out","w",stdout);
	#endif
	int n=read(),m;
	m=read();
	for(int i=1;i<=n;i++){
		fir[i]=-1;
	}
	for(int i=1;i<=m;i++){
		int a=read(),b;
		b=read();
		add(a,b);
	}
	for(int i=1;i<=n;i++){
		if(in[i]==0){
			qu.push(-i);
		}
	}
	while(qu.size()>0){
		int nw=-qu.top();
		qu.pop();
		printf("%d ",nw);
		for(int i=fir[nw];i!=-1;i=nxt[i]){
			in[v[i]]--;
			if(in[v[i]]==0){
				qu.push(-v[i]);
			}
		}
	}
	return 0;
}

