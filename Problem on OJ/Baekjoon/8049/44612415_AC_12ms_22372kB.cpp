#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<bitset>
// #define ONLINE_JUDGE
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

std::map<unsigned long long,std::map<unsigned long long,unsigned long long> > mp;

int n;
unsigned long long hash1[500010],hash2[500010],mod1=100000000000000003,mod2=1000000000000000003;

std::queue<int> Q;
std::bitset<500010> book;

std::vector<int> e[500010];
char s[500010];
void addEdge(int u,int v){
    e[u].push_back(v);
    return;
}

void dfs(int u){
    register int v;
    if(hash1[u]||hash2[u]) return;
    hash1[u]=hash2[u]=mod1+mod2+1140514+10919810;

    for(v=0;v<e[u].size();++v){
        dfs(e[u][v]);
        hash1[u]=hash1[e[u][v]]*mod1*1145141919819000+s[u]*(v+mod2)+hash1[u]*114514;
        hash2[u]=hash2[e[u][v]]*mod2*114051410919819+(v+1)*(s[u]+mod1)+hash2[u]*1919810;
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("name.in", "r", stdin);
    freopen("name.out", "w", stdout);
    #endif

    register int u,v,res=0;
    register char c;
    n=read();

    for(u=1;u<n;++u){
        loop:c=getchar();
        if(c<'A'||'Z'<c) goto loop;
        s[u]=c;
        v=read();
        addEdge(u,v);
        v=read();
        addEdge(u,v);
        v=read();
        addEdge(u,v);
    }

    dfs(1);

    Q.push(1);

    while(!Q.empty()){
        u=Q.front();
        Q.pop();
        for(auto v:e[u])
            if(!book[v]){
                book[v]=1;
                if(!mp[hash1[v]][hash2[v]]) mp[hash1[v]][hash2[v]]=1,++res;
                Q.push(v);
            }
    }

    print(res+1);

    #ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    #endif
    return 0;
}