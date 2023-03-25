#include<cstdio>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE unsigned long long
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

int arr[500010];
unsigned long long sum[500010],sumsum[500010],ans;

struct stresult{
    int data,index;
};

#include<cstring>
#define M >
#define mm(a,b) ((a)M(b)?(a):(b))
#define ST_DATA_TYPE int
int ln(int n){
	return 63-__builtin_clzll(n);
}
const int ST_MAX_I=500010;
const int ST_MAX_J=20;
struct ST{
	ST_DATA_TYPE f[ST_MAX_I][ST_MAX_J];//f[i][j]---[i,i+2^j-1]
    ST_DATA_TYPE book[ST_MAX_I][ST_MAX_J];

	void build(ST_DATA_TYPE *data,int size){
		memset(f,0,sizeof(f));
		int k=ln(size);
		for(register int i=1;i<=size;++i){
			f[i][0]=data[i];
            book[i][0]=i;
		}

		for(register int j=1;j<=k;++j){
			for(register int i=1;i<=size-(1<<j)+1;++i){
                if(f[i][j-1]>f[i+(1<<(j-1))][j-1]){
                    f[i][j]=f[i][j-1];
                    book[i][j]=book[i][j-1];
                }else{
                    f[i][j]=f[i+(1<<(j-1))][j-1];
                    book[i][j]=book[i+(1<<(j-1))][j-1];
                }
			}
		}
		return;
	}

	stresult query(int l,int r){
		int k=ln(r-l+1);
        if(f[l][k]>f[r-(1<<k)+1][k]){
            return (stresult){f[l][k],book[l][k]};
        }
		return (stresult){f[r-(1<<k)+1][k],book[r-(1<<k)+1][k]};
	}
}st;


struct stack_node{
    int l,r;
    char flag;
    stresult str;
    stack_node(int inl,int inr){
        l=inl;
        r=inr;
        flag=0;
        str=st.query(l,r);
        ans+=V();
        return;
    }

    unsigned long long V(){
        return ((str.index-l+1)*(sumsum[r+1]-sumsum[str.index])-(r-str.index+1)*(sumsum[str.index]-sumsum[l-1]))*str.data;
    }
    
    stack_node(){
        return;
    }
};

#define STACK_DATA_TYPE stack_node
const int STACK_SIZE=500010;struct STACK{STACK_DATA_TYPE _null,s[STACK_SIZE];int s_top;STACK(){s_top=0;return;}void push(STACK_DATA_TYPE in){s[s_top]=in;++s_top;return;}void pop(){--s_top;return;}void pop(int in){s_top-=in;return;}STACK_DATA_TYPE top(){return s[s_top-1];}void clear(){s_top=0;}bool empty(){if(s_top==0){return true;}else{return false;}}int size(){return s_top;}STACK_DATA_TYPE read(int in){return s[in];}};
STACK S;

int main(){
	#ifdef file
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	#endif

    register int i;
    int n=read();
    for(i=1;i<=n;++i) arr[i]=read();
    for(i=1;i<=n;++i) sum[i]=sum[i-1]+arr[i];
    for(i=1;i<=n;++i) sumsum[i+1]=sumsum[i]+sum[i];
    st.build(arr,n);

    register stack_node now(1,n),temp;
    S.push(now);
    while(!S.empty()){
        now=S.top(); 
        S.pop();
        if(now.flag==2||now.l>now.r) continue;
        else if(!now.flag)
            temp=stack_node(now.l,now.str.index-1);
        else if(now.flag==1)
            temp=stack_node(now.str.index+1,now.r);
        ++now.flag;
        S.push(now);
        S.push(temp);
    }

    print(ans);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}
