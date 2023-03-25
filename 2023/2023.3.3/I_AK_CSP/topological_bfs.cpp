#include<cstdio>
#include <queue>
#include <iostream>
// #define ONLINE_JUDGE
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}
int fir[10005];
int nxt[100005];
int v[100005];
int in[10005];
// int w[100005];
int now;
std::queue<int>a;
void add(int a,int b){
	now++;
	in[b]++;
	v[now]=b;
	nxt[now]=fir[a];
	fir[a]=now;
	return ;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("topological.in", "r", stdin);
	freopen("topological.out", "w", stdout);
	#endif
    int n=read(),m=read();
    for(int i=1;i<=n;i++){
        fir[i]=-1;
    }
	for(int i=1;i<=m;i++){
		int a=read();
		int b=read();
		add(a+1,b+1);
	}
	for(int i=1;i<=n;i++){
		if(in[i]==0){
			a.push(-i);
		}
	}
	while(a.size()>0){
		int temp=-a.front();
		a.pop();
		printf("%d\n",temp-1);
		for(int i=fir[temp];i!=-1;i=nxt[i]){
			in[v[i]]--;
			if(in[v[i]]==0){
				a.push(-v[i]);
			}
		}
	}
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}