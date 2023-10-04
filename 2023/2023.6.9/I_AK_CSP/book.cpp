#include <iostream>
#include <cstdio>
inline int read();

int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("book.in","r",stdin);
	freopen("book.out","w",stdout);
	#endif
    int n=read();
    int a=0,b=0,c=0;
    for(int i=1;i<=n;i++){
        int temp=read();
        if(temp==5){
            a++;
        }else if(temp==10){
            b++;
        }else if(temp==15){
            c++;
        }
        temp-=5;
        while(temp>=20&&c>0){
            c--;
            temp-=20;
        }
        while(temp>=10&&b>0){
            b--;
            temp-=10;
        }
        while(temp>=5&&a>0){
            a--;
            temp-=5;
        }
        if(temp!=0){
            printf("NO");
            return 0;
        }
    }
    printf("YES");
	return 0;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		c=='-'?f=-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f*x;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/


