#include <iostream>
#include <cstdio>
using namespace std;
char stack[300];
int top=0;
int main(){
    char a=getchar();
    while(a!=EOF){
        if(a=='('){
        	stack[top++]='(';
        }else if(a==')'){
        	top--;
        }
        a=getchar();
    }
    cout<<(top==0?"YES":"NO");
    return 0;
}