#include <cstdio>
#include <cstring>
using namespace std;

#define file
#define MAX_N 505
#define MAX_M MAX_N*MAX_N
const int INF=(1<<20);

int e[MAX_N][MAX_N],n,m;

int min(int a,int b);
void init();
inline int read();
void readGraph();
void Floyd_WarshallMatrix();

int main(){
	#ifdef file
	freopen("h.in", "r", stdin);
	freopen("3.out", "w", stdout);
	#endif

	init();
	readGraph();

	Floyd_WarshallMatrix();

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}
int k;
void Floyd_WarshallMatrix(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				e[i][j]=min(e[i][k]+e[k][j],e[i][j]);

	for(int i=1;i<=n;i++){
		printf("%d ",e[k][i]);
	}
		putchar('\n');
}

void addEdge(int u,int v,int w,int nowm){
	e[u][v]=w;
	return;
}

void readGraph(){
	n=read();
	m=read();
	k=read();
	int u,v,w;
	for(int i=1;i<=m;i++){
		u=read();
		v=read();
		w=read();
		addEdge(u,v,w,i);
	}
	return;
}

void init(){
	for(int i=0;i<MAX_N;i++){
		for(int j=0;j<MAX_N;j++){
			if(i==j) e[i][j]=0;
			else e[i][j]=INF;
		}
	}
}

inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();//?=if,:=else
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}

int min(int a,int b){
	return a<b?a:b;
}
