#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
bool a[2005][2005];
int b[405];
int ansnow[400005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("trouble.in","r",stdin);
	freopen("trouble.out","w",stdout);
	#endif
    int p=read();
    int now=0x3f3f3f3f;
    int siz2=0;
    for(int c=1;c<p;c++){
        // if(c==23){
        //     b[1]=c+2;
        // }
        bool yes=0;
        int siz=0;
        memset(b,0,sizeof(b));
        b[1]=c;
        memset(a,0,sizeof(a));
        // yes!=(b[1]!=0);
        for(int j=2;;j++){
            b[j]+=b[j-1]<<1;
            b[j+1]=b[j]/p;
            b[j]%=p;
            if(a[b[j-1]][b[j]]){
                break;
            }
            a[b[j-1]][b[j]]=1;
            if(((b[j]*2+(b[j-1]*2+((b[j-2]*2)>=p))/p)==c)&&(b[j]<=(p-1)/2)){
                yes=1;
                siz=j;
                break;
                // retu
            }
        }
        if(yes==0){
            continue;
        }
        int tsiz=siz;
        while(b[tsiz]==0){
        	tsiz--;
		}
        if(tsiz==now){
            bool change=0;
            for(int j=siz;j>=1;j--){
                if(b[j]>ansnow[j]){
                    break;
                }else if(b[j]<ansnow[j]){
                    change=1;
                    break;
                }
            }
            if(change==0){
            	continue;
			}
            for(int j=1;j<=siz;j++){
                ansnow[j]=b[j];
            }
        }else if(tsiz<now){
            now=tsiz;
			siz2=siz;
            for(int j=1;j<=siz;j++){
                ansnow[j]=b[j];
            }
        }
    }
    for(int j=siz2;j>=1;j--){
        printf("%d ",ansnow[j]);
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

