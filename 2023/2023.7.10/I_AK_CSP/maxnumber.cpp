#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <string>
inline int read();
int a[50005];
std::string aa,bb;
int b[50005];
int c[50005];
int d[50005];
std::stack<int>st;
void ans(int *a,int *c,int n,int k,std::string &d){
    while(st.size()>0){
        st.pop();
    }
    int kk=n-k;
    for(int i=1;i<=n;i++){
        while(st.size()>0&&k>0&&a[st.top()]<a[i]){
            c[st.top()]=1;
            k--;
            st.pop();
        }
        if(st.size()<kk)
            st.push(i);
        else{
            c[i]=1;
            k--;
        }
    }
    for(int i=n;i>=1&&k>0;i--){
        if(c[i]==0){
            c[i]=1;
            k--;
        }
    }
    for(int i=1;i<=n;i++){
        if(!c[i]){
            d=d+char(a[i]+'0');
        }
    }
    return ;
}
bool compare(std::string &a,std::string &b,int i,int j){
    int siza=a.size();
    int sizb=b.size();
    while(i<siza&&j<sizb){
        if(a[i]>b[j]){
            return 1;
        }else if(a[i]<b[j]){
            return 0;
        }
        i++;
        j++;
    }
    return ((siza-i)-(sizb-j))>0;
}
int main(){
	// #ifdef ONLINE_JUDGE
	// #else
	freopen("maxnumber.in","r",stdin);
	freopen("maxnumber.out","w",stdout);
	// #endif
    int m=read(),n,k;
    n=read();
    k=read();
    for(int i=1;i<=m;i++){
        a[i]=read();
    }
    for(int i=1;i<=n;i++){
        b[i]=read();
    }
    std::string an="";
    for(int i=0;i<=k;i++){
        memset(c,0,sizeof(c));
        memset(d,0,sizeof(d));
        aa="";
        bb="";
        if(m-i<0||n-k+i<0){
            continue;
        }
        // std::cerr<<i<<'\n';
        ans(a,c,m,m-i,aa);
        ans(b,d,n,n-k+i,bb);
        int siza=aa.size();
        int sizb=bb.size();
        std::string temp="";
        int ii=0,j=0;
        while(ii<siza&&j<sizb){
            if(compare(aa,bb,ii,j)){
                temp+=aa[ii];
                ii++;
            }else{
                temp+=bb[j];
                j++;
            }
        } 
        while(ii<siza){
            temp+=aa[ii];
            ii++;
        }
        while(j<sizb){
            temp+=bb[j];
            j++;
        }
        // std::cerr<<temp.size()<<' ';
        an=std::max(an,temp);
    }
    printf("%s",an.c_str());
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


