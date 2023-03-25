#include <cstdio>
#include <algorithm>
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

long long map[21][21][21],watch_c;

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

long long count(int x1,int y1,int z1,int x2,int y2,int z2){
    return watch_c=map[x2][y2][z2]-map[x2][y1-1][z2]-map[x1-1][y2][z2]-map[x2][y2][z1-1]+map[x2][y1-1][z1-1]+map[x1-1][y2][z1-1]+map[x1-1][y1-1][z2]-map[x1-1][y1-1][z1-1];
}

int main(){
	#ifdef file
	freopen("garbageheap.in", "r", stdin);
	freopen("garbageheap.out", "w", stdout);
	#endif

    register int la,lb,lc,i,j,k;
    register long long t;
    int T=read();
    while(T--){
    int a=read();
    int b=read();
    int c=read();

    for(i=1;i<=a;++i)
        for(j=1;j<=b;++j)
            for(k=1;k<=c;++k)
                map[i][j][k]=read();


    for(i=1;i<=a;++i){
        for(j=1;j<=b;++j)
            for(k=1;k<=c;++k)
                map[i][j][k]+=map[i][j][k-1];
        for(j=1;j<=b;++j)
            for(k=1;k<=c;++k)
                map[i][j][k]+=map[i][j-1][k];
    }

    for(i=1;i<=a;++i)
        for(j=1;j<=b;++j)
            for(k=1;k<=c;++k)
                map[i][j][k]+=map[i-1][j][k];

    t=0;

    for(la=0;la<=a;++la)
        for(lb=0;lb<=b;++lb)
            for(lc=0;lc<=c;++lc)
                for(i=1;i+la<=a;++i)
                    for(j=1;j+lb<=b;++j)
                        for(k=1;k+lc<=c;++k)
                            t=std::max(count(i,j,k,i+la,j+lb,k+lc),t);


    printf("%lld",t);
    if(t!=1) printf("\n\n");
    }

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

INPUT_DATA_TYPE read(){
    register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();
    while(c<'0'||'9'<c)f=(c=='-'),c=getchar();//?=if,:=else
    while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return f?-x:x;
}

void print(OUTPUT_DATA_TYPE x){
    register char s[20];
    register int i=0;
    if(x<0){
        x=-x;
        putchar('-');
    }
    if(x==0){
        putchar('0');
        return;
    }
    while(x){
        s[i++]=x%10;
        x/=10;
    }
    while(i){
        putchar(s[--i]+'0');
    }
    return;
}