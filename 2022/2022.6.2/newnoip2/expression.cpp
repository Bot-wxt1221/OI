#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
int pow(int a,int b){
	int temp=1;
	for(int i=1;i<=b;i++){
		temp*=a;
	}
	return temp;
}
string a,b;
int fir[300];
stack<char>d;
stack<int>e;
int main(){
	freopen("expression.in","r",stdin);
	freopen("expression.out","w",stdout);
	fir['-']=fir['+']=1;
	fir['*']=fir['/']=1;
	fir['^']=1;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if('0'<=a[i]&&a[i]<='9'){
			int c=0;
			while('0'<=a[i]&&a[i]<='9'){
				c=(a[i]-'0')+c*10;
				i++;
			}
			b+=(c+'0');
			b+=' ';
			i--;
		}else{
			if(a[i]=='('){
				d.push('(');
			}else if(a[i]==')'){
				while(d.size()>0&&d.top()!=')'){
					if(d.top()!='(')
						b+=d.top();
					d.pop();
				}
			}else{
				while(d.size()>0&&fir[d.top()]>=fir[a[i]]){
					b+=d.top();
					d.pop();
				}
				d.push(a[i]);
			}
		}
	}
	for(int i=0;i<b.size();i++){
		if(b[i]==' '){
			continue;
		}else if('0'<=b[i]&&b[i]<='9'){
			int c=0;
			while('0'<=b[i]&&b[i]<='9'){
				c=c*10+(b[i]-'0');
				i++;
			}
			e.push(c);
			i--;
		}else{	
			int aa=e.top();
			e.pop();
			int c=e.top();
			e.pop();
			int d=0;
			if(b[i]=='-'){
				d=c-aa;
			}else if(b[i]=='+'){
				d=c+aa;
			}else if(b[i]=='^'){
				d=pow(c,aa);
			}
			else if(b[i]=='*'){
				d=c*aa;
			}
			else if(b[i]=='-'){
				d=c-aa;
			}
			e.push(d);
		}
	}
	cout<<e.top();
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


