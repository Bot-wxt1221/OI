#include<cstdio>
#include<cstring>
// #define ONLINE_JUDGE
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

struct node{
    int l,r;
    char s[10],f;
    node(){
        l=r=f=-1;
        return;
    }
}tree[1000];

#define STACK_DATA_TYPE int
const int STACK_SIZE=1000;struct STACK{STACK_DATA_TYPE _null,s[STACK_SIZE];int s_top;STACK(){s_top=0;return;}void push(STACK_DATA_TYPE in){s[s_top]=in;++s_top;return;}void pop(){--s_top;return;}void pop(int in){s_top-=in;return;}STACK_DATA_TYPE top(){return s[s_top-1];}void clear(){s_top=0;}bool empty(){if(s_top==0){return true;}else{return false;}}int size(){return s_top;}STACK_DATA_TYPE read(int in){return s[in];}};

STACK S;
char s[1000],out[1000],map[128];
int tot;

void dfs(int u){
    if(tree[u].f==-1){
        printf("%s",tree[u].s);
        return;
    }
    
    if(tree[u].l!=-1){
        if(map[tree[u].f]>map[tree[tree[u].l].f]&&(tree[tree[u].l].f!=-1))
            putchar('(');
        dfs(tree[u].l);
        if(map[tree[u].f]>map[tree[tree[u].l].f]&&(tree[tree[u].l].f!=-1))
            putchar(')');
    }

    putchar(tree[u].f);

    if(tree[u].r!=-1){
        if((
        (map[tree[u].f]>map[tree[tree[u].r].f]&&(tree[u].f!='-'))||
        (map[tree[u].f]>=map[tree[tree[u].r].f]&&(tree[u].f=='-'))||
        (map[tree[u].f]>map[tree[tree[u].r].f]&&(tree[u].f!='/'))||
        (map[tree[u].f]>=map[tree[tree[u].r].f]&&(tree[u].f=='/'))
        )&&(tree[tree[u].r].f!=-1))
            putchar('(');
        dfs(tree[u].r);
        if((
        (map[tree[u].f]>map[tree[tree[u].r].f]&&(tree[u].f!='-'))||
        (map[tree[u].f]>=map[tree[tree[u].r].f]&&(tree[u].f=='-'))||
        (map[tree[u].f]>map[tree[tree[u].r].f]&&(tree[u].f!='/'))||
        (map[tree[u].f]>=map[tree[tree[u].r].f]&&(tree[u].f=='/'))
        )&&(tree[tree[u].r].f!=-1))
            putchar(')');
    }
    return;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	#endif

    register int i,j,outlen=0;
    scanf("%s",s);
    int len=strlen(s);
    map['+']=1;
    map['-']=1;
    map['*']=2;
    map['/']=2;
    map['(']=0;
    for(i=0;i<len;){
        if(s[i]!='+'&&s[i]!='-'&&s[i]!='*'&&s[i]!='/'&&s[i]!='('&&s[i]!=')'){
            while(s[i]!='+'&&s[i]!='-'&&s[i]!='*'&&s[i]!='/'&&s[i]!='('&&s[i]!=')'&&i<len)
                out[outlen++]=s[i++];
            out[outlen++]=' ';
        }else{
            if(s[i]==')'){
                while(!S.empty()&&S.top()!='('){
                    out[outlen++]=S.top();
                    out[outlen++]=' ';
                    S.pop();
                }
                S.pop();
                ++i;
                continue;
            }
            if(s[i]!='(')while(!S.empty()&&map[S.top()]>=map[s[i]]){
                out[outlen++]=S.top();
                out[outlen++]=' ';
                S.pop();
            }
            S.push(s[i++]);
        }
    }

    while(!S.empty()){
        out[outlen++]=S.top();
        out[outlen++]=' ';
        S.pop();
    }

    for(i=0;i<outlen;++i){
        if(out[i]==' '){
            ++i;
            continue;
        }else if(out[i]!='+'&&out[i]!='-'&&out[i]!='*'&&out[i]!='/'){
            j=0;
            while(out[i]!=' '&&i<outlen) tree[tot].s[j++]=out[i++];
        }else{
            tree[tot].r=S.top();
            S.pop();
            if(!S.empty()){
                tree[tot].l=S.top();
                S.pop();
            }
            tree[tot].f=out[i++];
        }
        S.push(tot++);
    }

    dfs(tot-1);

	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}