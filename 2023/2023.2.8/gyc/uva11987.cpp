#include<cstdio>
// #define ONLINE_JUDGE
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE long long
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

const int UFDS_SIZE=200010;
struct UFDS{
	int parents[UFDS_SIZE],cnt[UFDS_SIZE];
    long long sum[UFDS_SIZE];

	void build(int n){
		for(register int i=1;i<=n;++i){
			parents[i]=i+n;
            sum[i+n]=i;
            cnt[i+n]=1;
        }
		for(register int i=n+1;i<=(n<<1);++i){
			parents[i]=i;
        }
		return;
	}

	int find(int x){
		return x==parents[x]?x:(parents[x]=find(parents[x]));
//		printf("%d ",x);
	}

	void mergeset(int i,int j){
		parents[find(i)]=find(j);
		return;
	}

    void mergesingle(int i,int j){
        parents[i]=find(j);
    }

    void addset(int i,int j){
        sum[find(j)]+=sum[find(i)];
        cnt[find(j)]+=cnt[find(i)];
        return;
    }

    void addsingle(int i,int j){
        sum[find(j)]+=i;
        cnt[find(j)]+=1;
    }

    void sep(int i){
        sum[find(i)]-=i;
        cnt[find(i)]-=1;
        return;
    }

    long long getsum(int i){
        return sum[find(i)];
    }

    long long getcnt(int i){
        return cnt[find(i)];
    }
}u;

int main(){
	// #ifndef ONLINE_JUDGE
	freopen("4.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	// #endif


    int n,m;
    register int i,p,q,a,b;
    register char op;
    while(scanf("%d%d",&n,&m)==2){
    u.build(n);
    for(i=0;i<m;++i){
        op=read();
        if(op==1){
            p=read();
            q=read();
            a=u.find(p);
            b=u.find(q);
            if(a!=b){
                u.addset(p,q);
                u.mergeset(p,q);
                
            }
        }else if(op==2){
            p=read();
            q=read();
            a=u.find(p);
            b=u.find(q);
            if(a!=b){
                u.sep(p);
                u.mergesingle(p,q);
                u.addsingle(p,q);
            }
        }else{
            p=read();
            print(u.getcnt(p));
            putchar(' ');
            print(u.getsum(p));
            putchar('\n');
        }
    }}

	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}
