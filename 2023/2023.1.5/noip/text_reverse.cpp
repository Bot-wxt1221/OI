#include <iostream>
#include <cstdio>
inline int read();
char temp2[10005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("text_reverse.in","r",stdin);
	freopen("text_reverse.out","w",stdout);
	#endif
	int T=read();
    while(T--){
        char temp=getchar();
        int siz=0;
        while(temp!='\n'&&temp!=EOF){
            if(temp==' '){
                for(int i=siz-1;i>=0;i--){
                    printf("%c",temp2[i]);
                }
                siz=0;
                printf(" ");
                temp=getchar();
                continue;
            }
            temp2[siz++]=temp;
            temp=getchar();
        }
        for(int i=siz-1;i>=0;i--){
            printf("%c",temp2[i]);
        }
        printf("\n");
    }
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


