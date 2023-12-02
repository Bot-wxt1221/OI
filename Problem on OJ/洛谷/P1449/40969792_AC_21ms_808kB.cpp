#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
using namespace std;
char a[1000];
int Stack[1000];
int top=0;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	scanf("%s",a);
	int temp=0;
	scanf("%s",&a);
	for(int i=0;i<strlen(a);i++){
		if('0'<=a[i]&&a[i]<='9'){
			temp=temp*10+a[i]-'0';
		}else if(a[i]=='.'){
			Stack[top++]=temp;
			temp=0;
		}
		else if(a[i]!='@'){
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
			if(cc<0){
				printf("");
			}
		}
	}
	cout<<Stack[top-1];
	return 0;
}

