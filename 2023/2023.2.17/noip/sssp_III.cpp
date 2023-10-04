#include<cstdio>
// #define ONLINE_JUDGE
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}
int u[10005],v[10005],w[10005];
int dis[10005];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("sssp_III.in", "r", stdin);
	freopen("sssp_III.out", "w", stdout);
	#endif
	int n=read(),m;
	m=read();
	int so=read()+1;
	for(int i=1;i<=m;i++){
		u[i]=read()+1;
		v[i]=read()+1;
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		dis[i]=0x3f3f3f3f;
	}
	dis[so]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=m;i++){
			if(dis[u[i]]!=0x3f3f3f3f&&dis[v[i]]>dis[u[i]]+w[i]){
				dis[v[i]]=dis[u[i]]+w[i];
			}
		}
	}
	for(int i=1;i<=m;i++){
			if(dis[u[i]]!=0x3f3f3f3f&&dis[v[i]]>dis[u[i]]+w[i]){
				printf("NEGATIVE CYCLE\n");
				return 0;
			}
		}
	for(int i=1;i<=n;i++){
		if(dis[i]<0x3f3f3f3f)
			printf("%d\n",dis[i]);
		else
			printf("INF\n");
	}
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}
