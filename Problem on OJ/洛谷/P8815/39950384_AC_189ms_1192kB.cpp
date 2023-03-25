#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
long long read(){
	char temp=getchar();
	long long f=1,x=0;
	while('0'>temp||temp>'9'){
		(temp=='-')?(f=-1):0;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}
class node{
	public:
		int ansa,ansb;
		int i;
		node(int a,int b,int j){
			ansa=a;
			ansb=b;
			i=j;
		}
		node(){
			ansa=ansb=i=0;
		}
};
stack<node>calc;
stack<char>ex;
int nowb=0;
int ansa=0,ansb=0;
char bac[1000005];
int dfs(){
	for(int i=1;i<=nowb;i++){
		if(i==nowb-1){
			i=nowb-1;
		}
		if(bac[i]=='1'||bac[i]=='0'){
			calc.push(node({0,0,i})); 
		}else if(bac[i]=='|'){
			node a=calc.top();
			calc.pop();
			node b=calc.top();
			calc.pop();
			node in;
			in.i=i;
			bac[i]=(((bac[a.i]-'0')||(bac[b.i]-'0'))+'0');
			if(bac[b.i]=='1'){
				in.ansa=b.ansa;
				in.ansb=b.ansb+1;
			}else{
				in.ansa=a.ansa+b.ansa;
				in.ansb=a.ansb+b.ansb;
			}
			calc.push(in);
		}else{
			node a=calc.top();
			calc.pop();
			node b=calc.top();
			calc.pop();
			node in;
			in.i=i;
			bac[i]=(((bac[a.i]-'0')&&(bac[b.i]-'0'))+'0');
			if(bac[b.i]=='0'){
				in.ansa=b.ansa+1;
				in.ansb=b.ansb;
			}else{
				in.ansa=a.ansa+b.ansa;
				in.ansb=a.ansb+b.ansb;
			}
			calc.push(in);
		}
	}
	ansa=calc.top().ansa;
	ansb=calc.top().ansb;
	return bac[calc.top().i]-'0';
}
int main(){
// 	freopen("expr.in","r",stdin);
// 	freopen("expr.out","w",stdout);
	char temp=getchar();
	while(temp!=EOF){
		if(temp=='0'||temp=='1'){
			bac[++nowb]=temp;
		}else if(temp=='|'){
			while(ex.size()>0&&(ex.top()=='&'||ex.top()=='|')){
				bac[++nowb]=ex.top();
				ex.pop();
			}
			ex.push('|'); 
		}else if(temp=='&'){
			while(ex.size()>0&&ex.top()=='&'){
				bac[++nowb]=ex.top();
				ex.pop();
			}
			ex.push('&');
		}else if(temp=='('){
			ex.push('(');
		}else if(temp==')'){
			while(ex.size()>0&&ex.top()!='('){
				bac[++nowb]=ex.top();
				ex.pop();
			}
			ex.pop();
		}
		temp=getchar();
	}
	while(ex.size()>0){
		bac[++nowb]=ex.top();
		ex.pop();
	}
	printf("%d\n",dfs());
	printf("%d %d",ansa,ansb);
	return 0;
}