#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    char a=getchar();
    while(a!=EOF){
        if(a=='('){
            while(a==')'){
                a=getchar();
                if(a==EOF){
                    cout<<"NO";
                    return 0;
                }
            }
        }
        a=getchar();
    }
    cout<<"YES";
    return 0;
}