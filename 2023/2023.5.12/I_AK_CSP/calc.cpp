#include <iostream>
#include <stack>
#include <cstdio>
#define int long long
#define mod 1000000007
inline int read();
int fir[300];
std::stack<char> a;
std::stack<int> b;
bool isfu[10000005];
int last[10000005];
signed main(){
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
    bool num=0;
    int count=0;
    char temp;
    int n=0;
    fir['+']=fir['-']=1;
    fir['*']=2;
    int summ=0;
    while((temp=getchar())!=EOF&&temp!='\n'){
        summ++;
        if('0'<=temp&&temp<='9'){
            num=1;
            count=(count<<3)+(count<<1)+(temp^48);
            count%=mod;
        }else if(temp!='('&&temp!=')'){
            if(num){
                num=0;
                last[++n]=count;
                count=0;
            }
            while(a.size()>0&&fir[a.top()]>=fir[temp]&&a.top()!='('){
                last[++n]=a.top();
                isfu[n]=1;
                a.pop();
            }
            a.push(temp);
        }else if(temp=='('){
            if(num){
                num=0;
                last[++n]=count;
                count=0;
            }
            a.push(temp);
        }else{
            if(num){
                num=0;
                last[++n]=count;
                count=0;
            }
            while(a.size()>0&&a.top()!='('){
                last[++n]=a.top();
                isfu[n]=1;
                a.pop();
            }
            a.pop();
        }
    }
    if(num){
        num=0;
        last[++n]=count;
        count=0;
    }
    while(a.size()>0){
        last[++n]=a.top();
        isfu[n]=1;
        a.pop();
    }
    for(int i=1;i<=n;i++){
        if(i==n){
            std::cerr<<b.size();
        }
        if(isfu[i]==0){
            b.push(last[i]);
        }else{
            int y=b.top();
            b.pop();
            int x=b.top();
            b.pop();
            if(last[i]=='+'){
                b.push((x+y)%mod);
            }else if(last[i]=='-'){
                b.push((x-y)%mod);
            }else if(last[i]=='*'){
                b.push((x*y)%mod);
            }
        }
    }
    printf("%lld",b.top());
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


