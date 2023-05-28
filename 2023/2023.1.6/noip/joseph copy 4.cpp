#include<list>
#include<cstdio>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

std::list<int> list;

int main(){
	#ifdef file
	freopen("joseph.in", "r", stdin);
	freopen("joseph.out", "w", stdout);
	#endif

    register int i;
    int n=read();
    int m=read();
    for(i=1;i<=n;++i){
        list.push_back(i);
    }

    while(n--){
        for(i=1;i<m;++i){
            list.push_back(list.front());
            list.pop_front();
        }
        printf("%d ",list.front());
        list.pop_front();
    }


	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}