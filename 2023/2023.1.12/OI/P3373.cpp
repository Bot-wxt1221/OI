#include<cstdio>
#include<cmath>
// #define ONLINE_JUDGE
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

int arr[100010];
const int p=571373;

struct block_array{
    int len;
    long long arr[100010],id[100010],tag[100010],s[100010];
    void build(int n,int *data){
        register int i;
        len=std::sqrt(n);
        for(i=1;i<=n;++i) arr[i]=data[i],id[i]=(i-1)/len+1,s[id[i]]+=arr[i];
        return;
    }

    void add(int l,int r,long long c){
        register int i;
        int begin=id[l],end=id[r];
        if(begin==end){
            for(i=l;i<r;++i) arr[i]+=c,s[begin]+=c;
            return;
        }
        for(i=l;id[i]==begin;++i) arr[i]+=c,s[begin]+=c;
        for(i=begin+1;i<end;++i) tag[i]+=c,s[i]+=c*len;
        for(i=r;id[i]==end;--i) arr[i]+=c,s[end]+=c;
        return;
    }

    long long query(int l,int r){
        register int i;
         long long ans=0;
        int begin=id[l],end=id[r];
        if(begin==end){
            for(i=l;i<r;++i) ans+=arr[i]+tag[begin];
            return ans;
        }
        for(i=l;id[i]==begin;++i) ans+=arr[i]+tag[begin];
        for(i=begin+1;i<end;++i) ans+=s[i];
        for(i=r;id[i]==end;--i) ans+=arr[i]+tag[end];
        return ans;
    }
}ba;


int main(){
	#ifndef ONLINE_JUDGE
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

    int n=read();
    int m=read();

    for(register int i=1;i<=n;++i) arr[i]=read();

    ba.build(n,arr);

    char op;
    register int l,r,c;

    for(register int i=1;i<=m;++i){
        op=read();
        if(op==1){
            l=read();
            r=read();
            c=read();
            ba.add(l,r,c);
        }else{
            l=read();
            r=read();
            printf("%lld\n",ba.query(l,r));
        }
    }

	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}