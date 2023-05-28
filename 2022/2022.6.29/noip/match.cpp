#include <iostream>
#include <cstdio>
#include <stack>
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
stack<char>st;
bool matc[300][300];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	matc['['][']']=1;
	matc['('][')']=1;
	char a;
	int ans=0;
	while((a=getchar())!=EOF&&(a=='['||a==']'||a=='('||a==')')){
		if(a=='['||a=='('){
			st.push(a);
		}else if(st.size()>0&&matc[st.top()][a]==1){
			st.pop();
		}else if(st.size()>0&&matc[st.top()][a]==0){
			ans++;
		}else{
			ans++;
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



