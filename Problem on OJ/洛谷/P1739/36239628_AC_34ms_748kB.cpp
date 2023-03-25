#include <iostream>
#include <cstdio>
using namespace std;
int top=0;
int main(){
    char a=getchar();
    while(a!='@'){
        if(a=='('){
        	top++;
        }else if(a==')'){
        	if(top==0){
        		cout<<"NO";
        		return 0;
        	}
        	top--;
        }
        a=getchar();
    }
    cout<<(top==0?"YES":"NO");
    return 0;
}