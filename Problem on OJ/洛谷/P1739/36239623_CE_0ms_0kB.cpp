#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    char a=getchar();
    int b=1;
    while(a!=EOF){
        if(a=='('){
            b++;
        }
        if(a==')'){
            b--;
        }
        if(b==1){
    cout<<"YES";
        }
        else{
            cout<<"NO";
        }
    return 0;
}
