#include <iostream>
#include <cstdio>
#include <cmath>
inline int read();
long double x[20];
long double y[20];
bool back[20];
bool shot[20];
int more;
int used=0;
int ans=0,n;
void dfs(int now){
    if(more==0){
        ans=std::min(ans,used);
        return ;
    }
    bool yes=0;
    for(int i=1;i<=n;i++){
        if(shot[i]){
            continue;
        }
        for(int j=1;j<=n;j++){
            if(i==j||shot[j]){
                continue;
            }
            long double a1=x[i]*x[i];
            long double b1=x[i];
            long double c1=y[i];
            long double a2=x[j]*x[j];
            long double b2=x[j];
            long double c2=y[j];
            b2=b2*a1/a2;
            c2=c2*a1/a2;
            a2=a1;
            long double b=(c2-c1)/(b2-b1);
            long double a=(c1-b1*b)/a1;
            if(a>=0){
                continue;
            }
            yes=1;
            shot[i]=shot[j]=1;
            more-=2;
            used++;
            for(int m=1;m<=n;m++){
                if(shot[m]){
                    continue;
                }
                if(std::abs(y[m]-a*x[m]*x[m]-b*x[m])<=1e-4){
                    shot[m]=1;
                    back[m]=1;
                    more--;
                }
            }
            dfs(now+1);
            used--;
            more+=2;
            shot[i]=shot[j]=0;
            for(int m=1;m<=n;m++){
                if(back[m]){
                    shot[m]=0;
                    more++;
                }
            }
        }
    }
    if(!yes){
        ans=std::min(ans,used+more);
        return ;
    }
    return ;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("angrybirds.in","r",stdin);
	freopen("angrybirds.out","w",stdout);
	#endif
    int T=read();
    while(T--){
        n=read();
        read();
        more=n;
        ans=0x3f3f3f3f;
        for(int i=1;i<=n;i++){
            scanf("%Lf%Lf",&x[i],&y[i]);
            shot[i]=0;
        }
        dfs(1);
        printf("%d\n",ans);
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


