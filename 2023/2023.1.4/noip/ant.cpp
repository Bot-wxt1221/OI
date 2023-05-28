#include<cstdio>
#include<algorithm>
 #define file
#define INPUT_DATA_TYPE long long
#define OUTPUT_DATA_TYPE long long

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int main(){
	#ifdef file
	freopen("ant.in", "r", stdin);
	freopen("ant.out", "w", stdout);
	#endif
	
	int T=read();
	while(T--){
		register long long i,max=0,min=0,temp;
		long long L=read();
		long long n=read();
		
		for(i=0;i<n;++i){
			temp=read();
			min=std::max(min,std::min(temp,L-temp));
			max=std::max(max,std::max(temp,L-temp));
		}
		print(min);
		putchar(' ');
		print(max);
		putchar('\n');
	}

	


	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

INPUT_DATA_TYPE read(){
    register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();
    while(c<'0'||c>'9')f=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
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
