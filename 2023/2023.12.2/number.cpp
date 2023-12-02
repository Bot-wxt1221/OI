#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
char temp[20];
int siz;
int fans=0;
void dfs(int now){
    if(now==siz){
        bool first=1;
        int l=1,r=siz;
        if(temp[l]==0){
            l++;
        }
        int ans=1;
        while(l<=r){
            if(l==r){
                if(temp[l]%2!=0){
                    ans=0;
                }
            }else if(temp[l]==temp[r]){
                ans*=(std::min(int(temp[l]),9)-std::max(int(temp[l]-9),int(first))+1);
            }else{
                ans=0;
            }
            l++;
            r--;
            first=0;
        }
        fans+=ans;
        return ;
    }
    dfs(now+1);
    if(temp[now]!=0){
        temp[now]--;
        temp[now+1]+=10;
        dfs(now+1);
        temp[now+1]-=10;
        temp[now]++;
    }
    return ;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	#endif
    int T=read();
    while(T--){
        scanf("%s",temp+1);
        siz=strlen(temp+1);
        for(int i=1;i<=siz;i++){
            temp[i]-='0';
        }
        fans=0;
        dfs(1);
        printf("%d\n",fans);
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

