#include<cstdio>
#include<cstring>
// #define ONLINE_JUDGE
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

struct edge{
    int to,next;
    edge(){
        next=-1;
        return;
    }
}e[100010];
int head[100010],tot,depth[100010],parent[100010],rd[100010];
char type[100010];

#define STACK_DATA_TYPE int
const int STACK_SIZE=100010;struct STACK{STACK_DATA_TYPE _null,s[STACK_SIZE];int s_top;STACK(){s_top=0;return;}void push(STACK_DATA_TYPE in){s[s_top]=in;++s_top;return;}void pop(){--s_top;return;}void pop(int in){s_top-=in;return;}STACK_DATA_TYPE top(){return s[s_top-1];}void clear(){s_top=0;}bool empty(){if(s_top==0){return true;}else{return false;}}int size(){return s_top;}STACK_DATA_TYPE read(int in){return s[in];}};

STACK S;

void addEdge(int u,int v){
    ++rd[v];
    e[tot].to=v;
    e[tot].next=head[u];
    head[u]=tot;
    ++tot;
    return;
}

void dfs(int u,int p,int d){
    char flag=0;
    parent[u]=p;
    depth[u]=d;
    for(int i=head[u];~i;i=e[i].next)
        if(e[i].to!=p){
            flag=1;
            dfs(e[i].to,u,d+1);
        }

    if(d) type[u]=flag+1;
    return;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("r_tree.in", "r", stdin);
	freopen("r_tree.out", "w", stdout);
	#endif

    register int i,j,d,u,v;
    int n=read();
    memset(head,-1,sizeof(head));
    for(i=0;i<n;++i){
        u=read();
        d=read();

        for(j=0;j<d;++j){
            v=read();
            addEdge(u,v);
        }
    }

    for(i=0;i<n;++i){
        if(!rd[i]){
            dfs(i,-1,0);
            break;
        }
    }

    for(i=0;i<n;++i){
        printf("node %d: parent = %d, depth = %d, %s, [",i,parent[i],depth[i],type[i]==0?"root":(type[i]==1?"leaf":"internal node"));
        S.clear();
        for(j=head[i];~j;j=e[j].next) S.push(e[j].to);
        if(!S.empty()){
            print(S.top());
            S.pop();
            while(!S.empty()){
                putchar(',');
                putchar(' ');
                print(S.top());
                S.pop();
            }
        }
        putchar(']');
        putchar('\n');
    }


	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}