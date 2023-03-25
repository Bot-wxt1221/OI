#include<cstdio>
#include<algorithm>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

int main(){
	#ifdef file
	freopen("maxsubarray.in", "r", stdin);
	freopen("maxsubarray.out", "w", stdout);
	#endif

    register int now;
    register int pre=0;
    register int max=-0x7fffffff;
    while(~scanf("%d",&now)){
        if(now>now+pre){
            pre=now;
        }else{
            pre+=now;
        }
        max=std::max(max,pre);
    }

    print(max);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

