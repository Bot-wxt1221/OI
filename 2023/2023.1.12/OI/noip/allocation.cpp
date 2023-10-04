#include<cstdio>
#include<algorithm>
#include<set>
// #define ONLINE_JUDGE
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

long long w[1000000],n,k;

int check(int p){
    register int i,ans=1,now=0;
    for(i=0;i<n;++i)
        if(now+w[i]>p){
            ++ans;
            now=w[i];
        }else{
            now+=w[i];
        }
    return ans<=k;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("allocation.in", "r", stdin);
	freopen("allocation.out", "w", stdout);
	#endif

    register int i;
    register long long l,r,sum=0,mid,max=0;
    n=read();
    k=read();
    for(i=0;i<n;++i) w[i]=read(),sum+=w[i],max=std::max(max,w[i]);
    l=std::max((long long)(sum*1.0/k+0.5),max),r=sum+1;
    while(l+10<r){
        mid=(l+r)>>1;
        if(check(mid)){
            r=mid+1;
        }else{
            l=mid;
        }
    }

    for(i=l;i<r;++i){
        if(check(i)){
            print(i);
            return 0;
        }
    }

	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}