#include <iostream>
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
    }
    cout<<"YES";
    return 0;
}