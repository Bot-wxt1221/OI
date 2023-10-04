#include <iostream>
#include <cstdio>
inline int read();
int a,b,c,m;
int dis[10000005];
int dis2[10000005];
class node{
    public:
        int la,ra,lb,rb,lc,rc,h;
}aa[10000005];
int convert(int x,int y,int z){
    return ((x-1)*b+(y-1))*c+z;
}
bool check(int m){
    for(int i=1;i<=a*b*c;i++){
        dis[i]=dis2[i];
    }
    for(int i=1;i<=m;i++){
        dis[convert(aa[i].la,aa[i].lb,aa[i].lc)]-=aa[i].h;
        dis[convert(aa[i].ra+1,aa[i].lb,aa[i].lc)]+=aa[i].h;
        dis[convert(aa[i].la,aa[i].rb+1,aa[i].lc)]+=aa[i].h;
        dis[convert(aa[i].la,aa[i].lb,aa[i].rc+1)]+=aa[i].h;
        dis[convert(aa[i].ra+1,aa[i].rb+1,aa[i].lc)]-=aa[i].h;
        dis[convert(aa[i].la,aa[i].rb+1,aa[i].rc+1)]-=aa[i].h;
        dis[convert(aa[i].ra+1,aa[i].lb,aa[i].rc+1)]-=aa[i].h;
        dis[convert(aa[i].ra+1,aa[i].rb+1,aa[i].rc+1)]+=aa[i].h;
    }
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            for(int kk=1;kk<=c;kk++){
                dis[convert(i,j,kk)]+=dis[convert(i,j,kk-1)];
                dis[convert(i,j,kk)]+=dis[convert(i-1,j,kk)];
                dis[convert(i,j,kk)]+=dis[convert(i,j-1,kk)];
                dis[convert(i,j,kk)]-=dis[convert(i-1,j-1,kk)];
                dis[convert(i,j,kk)]-=dis[convert(i,j-1,kk-1)];
                dis[convert(i,j,kk)]-=dis[convert(i-1,j,kk-1)];
                dis[convert(i,j,kk)]+=dis[convert(i-1,j-1,kk-1)];
                if(dis[convert(i,j,kk)]<0){
                    return 1;
                }
            }
        }
    }
    return 0;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	a=read();
    b=read();
    c=read();
    m=read();
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            for(int kk=1;kk<=c;kk++){
                dis[convert(i,j,kk)]=read();
            }
        }
    }
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            for(int kk=1;kk<=c;kk++){
                dis2[convert(i,j,kk)]+=dis[convert(i,j,kk)];
                dis2[convert(i,j,kk)]-=dis[convert(i,j,kk-1)];
                dis2[convert(i,j,kk)]-=dis[convert(i-1,j,kk)];
                dis2[convert(i,j,kk)]-=dis[convert(i,j-1,kk)];
                dis2[convert(i,j,kk)]+=dis[convert(i-1,j-1,kk)];
                dis2[convert(i,j,kk)]+=dis[convert(i,j-1,kk-1)];
                dis2[convert(i,j,kk)]+=dis[convert(i-1,j,kk-1)];
                dis2[convert(i,j,kk)]-=dis[convert(i-1,j-1,kk-1)];
            }
        }
    }
    for(int i=1;i<=m;i++){
        aa[i].la=read();
        aa[i].ra=read();
        aa[i].lb=read();
        aa[i].rb=read();
        aa[i].lc=read();
        aa[i].rc=read();
        aa[i].h=read();
    }
    int l=0,r=m+4;
    while((r-l)>=4){
        int mid=(l+r)/2;
        if(!check(mid)){
            l=mid-1;
        }else{
            r=mid+1;
        }
    }
    for(int i=l;i<=r;i++){
        if(check(i)){
            printf("%d",i);
            return 0;
        }
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


