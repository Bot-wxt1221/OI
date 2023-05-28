#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
using namespace std;
char a[1000];
int Stack[1000];
int top=0;
int main(){
	freopen("Reverse_Polish_notation.in","r",stdin);
	freopen("Reverse_Polish_notation.out","w",stdout);
//	scanf("%s",a);
	int temp=0;
	while(scanf("%s",&a)!=EOF){
		if('0'<=a[0]&&a[0]<='9'){
			std::stringstream aa;
			aa<<a;
			int b;
			aa>>b;
			Stack[top++]=b;
		}
		else{
			int aa=Stack[top-1];top--;int bb=Stack[top-1];top--;int cc;
			if(a[0]=='/'){
				cc=bb/aa;
			}else if(a[0]=='*'){
				cc=bb*aa;
			}else if(a[0]=='+'){
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
