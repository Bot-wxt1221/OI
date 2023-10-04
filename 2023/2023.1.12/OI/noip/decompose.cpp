#include<cstdio>
#include<algorithm>
// #define ONLINE_JUDGE
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

int cnt,arr[40],bak;
void dfs(int step,int n,int now){
    if(n==0){
        ++cnt;
        print(bak);
        putchar('=');
        print(arr[0]);
        for(register int i=1;i<step;++i){
            putchar('+');
            print(arr[i]);
        }
        putchar('\n');
        return;
    }
    for(register int i=now;i<=std::min(n,bak-1);++i){
        arr[step]=i;
        dfs(step+1,n-i,i);
    }
    return;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("decompose.in", "r", stdin);
	freopen("decompose.out", "w", stdout);
	#endif

    register int n;
    while(~scanf("%d",&n)){
        cnt=0;
        bak=n;
        dfs(0,n,1);
        printf("total=");
        print(cnt);
        putchar('\n');
    }

	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}