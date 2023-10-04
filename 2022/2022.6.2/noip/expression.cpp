#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
using namespace std;
int you[300];
char Stack[1000];
int top=0;
char a[1000];
string temp;
signed main(){
	freopen("expression.in","r",stdin);
	freopen("expression.out","w",stdout);
	scanf("%s",a);
	you['+']=you['-']=1;//优先级初始化 
	you['*']=you['/']=2;
	you['^']=3;
	int now=0,have=0;
	for(int i=0;i<strlen(a);i++){
		if('0'<=a[i]&&a[i]<='9'){//数字直接输出 
			temp+=a[i];
			continue;
		}
		if(a[i]=='('){
			Stack[top++]=a[i];
		}else if(a[i]==')'){
			while(Stack[top-1]!='('&&top>0){ 
				top--;
				temp+=Stack[top];
			}
			top--;//左括号出栈 qwq 
		}else if((you[Stack[top-1]]<=you[a[i]]&&top>0)||top==0){
			Stack[top++]=a[i];
		}else{
			while(you[Stack[top-1]]>you[a[i]]&&top>0){
				top--;
				temp+=Stack[top];
			}
			Stack[top++]=a[i];
		}
	}
	while(top>0){
		if(Stack[top-1]!='('&&Stack[top-1]!=')')
			temp+=Stack[top-1];
		top--;
	}
	int Stack2[1000];
	memset(Stack2,0,sizeof(Stack2));
	top=0;
	for(int i=0;i<temp.size();i++){
		if('0'<=temp[i]&&temp[i]<='9'){
			Stack2[top++]=temp[i]-'0';
			continue;
		}
		{
			int aa=Stack2[top-1];top--;int bb=Stack2[top-1];top--;int cc;
			if(temp[i]=='/'){
				cc=bb/aa;
			}else if(temp[i]=='*'){
				cc=bb*aa;
			}else if(temp[i]=='+'){
				cc=bb+aa;
			}else if(temp[i]=='-'){
				cc=bb-aa;
			}else{
				cc=pow(bb,aa);
			}
			Stack2[top++]=cc;
		}
	}
	cout<<Stack2[top-1];
	return 0;
}
