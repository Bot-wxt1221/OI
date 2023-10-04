#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
inline int read();
int a[1000006];
int b[1000005];
int ans[1000005];
int nxt[1000005];
std::stack<int>st;
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("program.in","r",stdin);
	freopen("program.out","w",stdout);
	#endif
    int n=read(),m;
    for(int i=1;i<=n;i++){
        a[i]=read();
        nxt[i]=i-1;
    }
    nxt[n+1]=n;
    m=read();
    for(int i=1;i<=m;i++){
        b[i]=read();
    }
    std::sort(b+1,b+m+1);
    for(int i=1;i<=m;i++){
        int j;
        while(st.size()>0){
            st.pop();
        }
        for(j=b[i];j>=1;j=nxt[j]){
            if(st.size()>0&&st.top()==a[j]){
                ans[j]=1;
                st.pop();
            }else{
                st.push(a[j]);
                ans[j]=-1;
            }
            if(st.size()==0){
                break;
            }
        }
        if(st.size()!=0){
            printf("NO");
            return 0;
        }
        nxt[b[i]+1]=nxt[j];
    }
    while(st.size()>0){
        st.pop();
    }
    for(int j=nxt[n+1];j>=1;j=nxt[j]){
        if(st.size()>0&&st.top()==a[j]){
            ans[j]=1;
            st.pop();
        }else{
            st.push(a[j]);
            ans[j]=-1;
        }
    }
    if(st.size()!=0){
        printf("NO");
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(ans[i]==1){
            printf("+%d ",a[i]);
        }else{
            printf("-%d ",a[i]);
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


