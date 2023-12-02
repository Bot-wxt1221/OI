#include <iostream>
#include <cstdio>
#include <cstring>
#include <bitset>
#include <map>
#define int long long
inline int read();
char temp[50];
int a[50];
int n;
int ans=0;
int anss=0;
std::map<int,int> mymap;
std::map<int,int> mymap2;
void dfs(int i,int now,int cho,int aa){
    if(i==0){
        if(mymap.find(now)==mymap.end()){
            mymap.insert(std::pair<int,int>(now,cho));
            mymap2.insert(std::pair<int,int>(now,aa));
        }
        else{
            if(cho>mymap[now]){
                mymap[now]=std::max(mymap[now],cho);
                mymap2[now]=aa;
            }
        }
        return ;
    }
    dfs(i-1,now,cho,aa);
    dfs(i-1,now^a[i],cho+1,aa^(1<<(i)));
    return ;
}
void dfs2(int i,int now,int cho,int aa){
    if(i==n+1){
        if(mymap.find(now)!=mymap.end()){
            if(mymap[now]+cho>ans){
                ans=std::max(ans,mymap[now]+cho);
                anss=aa^(mymap2[now]);
            }
        }
        return ;
    }
    dfs2(i+1,now,cho,aa);
    dfs2(i+1,now^a[i],cho+1,aa^(1<<i));
    return ;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("jurassicremains.in","r",stdin);
	freopen("jurassicremains.out","w",stdout);
	#endif
    while(scanf("%lld",&n)!=EOF){
        ans=0;
        mymap.clear();
        for(int i=1;i<=n;i++){
            a[i]=0;
            scanf("%s",temp+1);
            int siz=strlen(temp+1);
            for(int j=1;j<=siz;j++){
                a[i]=a[i]^(1<<(temp[j]-'A'));
            }
        }
        int l=n/2;
        dfs(l,0,0,0);
        if(mymap.find(0)!=mymap.end()){
            ans=std::max(ans,mymap[0]);
        }
        dfs2(l+1,0,0,0);
        printf("%d\n",ans);
        for(int i=1;i<=n;i++){
            if(anss&(1<<i)){
                printf("%d ",i);
            }
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


