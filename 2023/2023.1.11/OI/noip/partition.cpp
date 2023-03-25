#include<cstdio>
#include<iostream>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

int arr[100010];

int main(){
	#ifdef file
	freopen("partition.in", "r", stdin);
	freopen("partition.out", "w", stdout);
	#endif

    register int i,j;
    int n=read();
    for(i=1;i<=n;++i) arr[i]=read();
    int key=arr[n];

    for(i=1,j=0;i<n;++i){
        if(arr[i]<=key){
            ++j;
            std::swap(arr[i],arr[j]);
        }
    }

    std::swap(arr[n],arr[j+1]);

    for(i=1;i<=n;++i){
        if(i==j+1) putchar('[');
        print(arr[i]);
        if(i==j+1) putchar(']');
        putchar(' ');
    }

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}