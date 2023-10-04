#include <iostream>
#include <cstdio>
using namespace std;
char a[1000];
int Stack[1000];
int top=0;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%s",a);
	for(int i=0;i<strlen(a);i++){
		if('0'<=a[i]&&a[i]<='9'){
			Stack[top++]=a[i]-'0';
		}else{
			int aa=Stack[top-1];top--;int bb=Stack[top-1];top--;int cc;
			if(a[i]=='/'){
				cc=bb/aa;
			}else if(a[i]=='*'){
				cc=bb*aa;
			}else if(a[i]=='+'){
				cc=bb+aa;
			}else{
				cc=bb-aa;
			}
			Stack[top++]=cc;
		}
	}
	cout<<Stack[top-1];
	return 0;
}


