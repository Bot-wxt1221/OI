#include <iostream>
using namespace std;
int main(){
    int max,num=0,a,b;
    for(int i=1;i<=7;i++){
        cin>>a>>b;
        a=a+b;
        if(a>8){
            if(a>max){
                num=i;
                max=a;
            }
        }
    }
    cout<<num;
    return 0;
}