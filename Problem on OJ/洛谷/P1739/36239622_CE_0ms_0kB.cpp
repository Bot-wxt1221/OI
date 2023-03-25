#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    char a=getchar();
    int a=1;
    while(a!=EOF){
        if(a=='('){
            a++;
        }
        if(a==')'){
            a--;
        }
        if(a==1){
    cout<<"YES";
        }
        else{
            cout<<"NO";
        }
    return 0;
}
