#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
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
int nxt[50005*2];
int fir[50005*2];
int v[50005*2];
int in[50005*2];
int now=0;
void add(int x,int y){
    now++;
    in[y]++;
    v[now]=y;
    nxt[now]=fir[x];
    fir[x]=now;
    return ;
}
int get(int x){
    if(x==1){
        return 0;
    }
    int a=sqrt(x);
    int ans=1;
    for(int i=2;(i<=a);i++){
        if(i==x/i){
            continue;
        }
        ans+=(x%i==0?i+(x/i):0);
        if(ans>=x){
            return -1;
        }
    }
    if(a*a==x){
        ans+=a;
    }
    if(ans>=x){
        return -1;
    }
    return ans;
}
int _max1=0,_max2=0;
int dfs(int now,int fa,int dep){
    // cout<<now<<' ';
    int _max1=dep;
    int _max2=dep;
    {
        for(int i=fir[now];i!=-1;i=nxt[i]){
            if(v[i]==fa){
                  continue;
            }
            int temp=dfs(v[i],now,dep+1);
            if(_max1<=temp){
                _max2=_max1;
                _max1=temp;
            }else if(_max2<=temp){
                _max2=temp;
            }
        }
        _max1-=dep;
        _max2-=dep;
        if(_max1+_max2>::_max1+::_max2){
            ::_max1=_max1;
            ::_max2=_max2;
        }
        return _max1+dep;
    }
}
int main(){
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout);
    int n=read();
    for(int i=1;i<=n;i++){
        fir[i]=-1;
    }
    for(int i=1;i<=n;i++){
        int temp=get(i);
        if(temp==-1||temp==0){
            continue;
        }
        add(temp,i);
        in[i]++;
        add(i,temp);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            _max1=_max2=0;
            dfs(i,i,0);
            ans=max(ans,_max1+_max2);
        }
    }
    printf("%d",ans);
	return 0;
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

